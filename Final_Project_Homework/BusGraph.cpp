#include "BusGraph.h"
#include <queue>
#include <algorithm>

BusGraph::BusGraph() {
    // 9개 정류장 목록 마스터 데이터 선언
    allStations = {
        "예술대학본관", "대운동장", "학생타운", 
        "문회루", "JBNU인터내셔널센터", "공과대학7호관", 
        "농업생명과학대학본관", "사회과학대학", "사범대학본관"
    };

    // 제공된 노선 및 가중치(시간) 데이터 완벽하게 하드코딩 (서버 구현 대체) [cite: 3]
    
    // 🔴 레드 라인 순환 노선
    addDirectedEdge("예술대학본관", "대운동장", "레드 라인", 5);
    addDirectedEdge("대운동장", "학생타운", "레드 라인", 3);
    addDirectedEdge("학생타운", "예술대학본관", "레드 라인", 8);

    // 🔵 블루 라인 순환 노선
    addDirectedEdge("예술대학본관", "문회루", "블루 라인", 6);
    addDirectedEdge("문회루", "JBNU인터내셔널센터", "블루 라인", 4);
    addDirectedEdge("JBNU인터내셔널센터", "공과대학7호관", "블루 라인", 5);
    addDirectedEdge("공과대학7호관", "예술대학본관", "블루 라인", 12);

    // 🟢 그린 라인 순환 노선
    addDirectedEdge("문회루", "공과대학7호관", "그린 라인", 6);
    addDirectedEdge("공과대학7호관", "농업생명과학대학본관", "그린 라인", 5);
    addDirectedEdge("농업생명과학대학본관", "사회과학대학", "그린 라인", 7);
    addDirectedEdge("사회과학대학", "사범대학본관", "그린 라인", 2);
    addDirectedEdge("사범대학본관", "문회루", "그린 라인", 7);
}

void BusGraph::addDirectedEdge(const std::string& src, const std::string& dest, const std::string& line, int weight) {
    adjList[src].push_back({dest, line, weight});
}

std::vector<std::string> BusGraph::getStationList() const {
    return allStations;
}

RouteResult BusGraph::findShortestPath(const std::string& start, const std::string& dest) {
    RouteResult result;
    result.totalTime = -1; // 기본값: 경로 없음

    if (start == dest) {
        result.path.push_back(start);
        result.totalTime = 0;
        return result;
    }

    // 다익스트라 연산을 위한 자료구조 선언
    std::unordered_map<std::string, int> dist;
    std::unordered_map<std::string, BusEdge> parent; // 경로 역추적용 부모 간선 저장
    
    for (const auto& station : allStations) {
        dist[station] = INT_MAX;
    }

    // 우선순위 큐 (가중치 최소 힙) -> <소요시간, 정류장이름>
    std::priority_queue<std::pair<int, std::string>, 
                        std::vector<std::pair<int, std::string>>, 
                        std::greater<std::pair<int, std::string>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int currentDist = pq.top().first;
        std::string current = pq.top().second;
        pq.pop();

        if (currentDist > dist[current]) continue;
        if (current == dest) break; // 목적지 도달 시 조기 종료

        for (const auto& edge : adjList[current]) {
            int nextDist = currentDist + edge.weight;
            if (nextDist < dist[edge.toStation]) {
                dist[edge.toStation] = nextDist;
                parent[edge.toStation] = {current, edge.lineName, edge.weight}; // 온 방향 기록
                pq.push({nextDist, edge.toStation});
            }
        }
    }

    // 목적지 도달 불가능한 경우 처리
    if (dist[dest] == INT_MAX) return result;

    // 경로 역추적 복원
    std::string curr = dest;
    std::vector<std::string> tempPath;
    std::vector<std::string> tempLines;

    while (curr != start) {
        tempPath.push_back(curr);
        BusEdge pEdge = parent[curr];
        tempLines.push_back(pEdge.lineName); // 사용된 노선명
        curr = pEdge.toStation;              // 부모 노드로 이동
    }
    tempPath.push_back(start);

    // 역순으로 정렬된 데이터를 올바른 정방향 순서로 뒤집기
    std::reverse(tempPath.begin(), tempPath.end());
    std::reverse(tempLines.begin(), tempLines.end());

    result.path = tempPath;
    result.lines = tempLines;
    result.totalTime = dist[dest];

    return result;
}