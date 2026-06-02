#include "AdjMatGraph.h" // 그래프 클래스 포함

int main()
{
	//AdjMatGraph g; // 새로운 그래프 객체 생성
	//for (int i = 0; i < 4; i++)
	//	g.insertVertex('A' + i); // 정점 삽입: 'A' 'B', ...
	//g.insertEdge(0, 1); // 간선 삽입
	//g.insertEdge(0, 3);
	//g.insertEdge(1, 2);
	//g.insertEdge(1, 3);
	//g.insertEdge(2, 3);
	//printf("인접 행렬로 표현한 그래프\n");
	//g.display();

	//FILE* fp;
	//fopen_s(&fp, "../text_out.txt", "w");
	////g.display(fp);
	//fclose(fp);

	//SrchAMGraph g2; // DFS 탐색기능이 있는 그래프 객체 생성
	//g.load("graph.txt"); // 파일 "graph.txt"로부터 g를 설정함
	//for (int i = 0; i < 8; i++)
	//	g2.insertVertex('A' + i); // 정점 삽입: 'A' 'B', ...
	//g2.insertEdge(0, 1); // 간선 삽입
	//g2.insertEdge(0, 3);
	//g2.insertEdge(1, 2);
	//g2.insertEdge(1, 3);
	//g2.insertEdge(2, 3);
	//g2.insertEdge(2, 3);
	//g2.insertEdge(4, 5);
	//g2.insertEdge(3, 6);
	//g2.insertEdge(5, 7);
	//g2.insertEdge(0, 5);
	//printf("그래프(graph.txt)\n");
	//g2.display(); // 그래프를 화면에 출력
	//printf("DFS ==> ");
	//g2.resetVisited(); // 모든 정점을 방문하지 않았다고 하고
	//g2.DFS(0); // 0번째 정점(A)에서 깊이 우선 탐색 시작
	//printf("\n");

	//WGraph wg;
	//wg.load("../graph.txt");
	//wg.display();

	WGraphMST g3;
	g3.load("graph.txt");
	cout << "입력 그래프: graph.txt" << endl;
	g3.display();
	cout << "MST By Kruskal's Algorithm" << endl;
	g3.Kruskal();

	return 0;

	return 0;
}
