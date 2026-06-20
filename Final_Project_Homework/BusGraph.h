#ifndef BUSGRAPH_H
#define BUSGRAPH_H

#include <string>
#include <vector>
#include <unordered_map>
#include <climits>
#include <QString>

// 간선(정류장 간 연결 도로) 정보 구조체
struct BusEdge {
    std::string toStation; // 도착 정류장 이름
    std::string lineName;  // 버스 노선 이름 (레드, 블루, 그린)
    int weight;            // 이동 소요 시간 (분)
};

// 최단 경로 탐색 결과를 담는 구조체
struct RouteResult {
    std::vector<std::string> path;     // 방문 정류장 순서
    std::vector<std::string> lines;    // 탑승해야 하는 노선 순서
    int totalTime;                     // 총 소요 시간 (분)
};

class BusGraph {
private:
    // 인접 리스트(Adjacency List) 방식으로 방향 그래프 구현
    std::unordered_map<std::string, std::vector<BusEdge>> adjList;
    std::vector<std::string> allStations;

public:
    BusGraph();
    void addDirectedEdge(const std::string& src, const std::string& dest, const std::string& line, int weight);
    
    // 다익스트라(Dijkstra) 알고리즘 기반 최단 시간 경로 탐색
    RouteResult findShortestPath(const std::string& start, const std::string& dest);
    
    std::vector<std::string> getStationList() const;
};

#endif // BUSGRAPH_H