#define _CRT_SECURE_NO_WARNINGS
#include "Location2D.h"
#include <stack>
#include <stdio.h>
#include <deque>

#define MAZE_SIZE 6
using namespace std;


char map[MAZE_SIZE][MAZE_SIZE] = {
{'1', '1', '1', '1', '1', '1'},
{'e', '0', '1', '0', '0', '1'},
{'1', '0', '0', '0', '1', '1'},
{'1', '0', '1', '0', '1', '1'},
{'1', '0', '1', '0', '0', 'x'},
{'1', '1', '1', '1', '1', '1'},
};
bool isValidLoc(int r, int c)
{
	if (r < 0 || c < 0 || r >= MAZE_SIZE || c >= MAZE_SIZE) return false;
	else return map[r][c] == '0' || map[r][c] == 'x';
}
void main() {
	printf("1: DFS(stack)\n2: DFS(deque)\n3: BFS(deque)\n탐색 방법을 선택하세요: ");
	int type = 0;
	scanf(" %d", &type);
	if (type == 1) {
		printf("DFS stack 실행\n");
		stack<Location2D> locStack;
		Location2D entry(1, 0);
		locStack.push(entry);
		while (locStack.empty() == false) {
			Location2D here = locStack.top();
			locStack.pop();
			int r = here.row, c = here.col;
			printf("(%d,%d) ", r, c);
			if (map[r][c] == 'x') {
				printf(" 미로 탐색 성공\n");
				return;
			}
			else {
				map[r][c] = '.';
				if (isValidLoc(r - 1, c)) locStack.push(Location2D(r - 1, c));
				if (isValidLoc(r + 1, c)) locStack.push(Location2D(r + 1, c));
				if (isValidLoc(r, c - 1)) locStack.push(Location2D(r, c - 1));
				if (isValidLoc(r, c + 1)) locStack.push(Location2D(r, c + 1));
			}
		}
		printf("미로 탐색 실패\n");
	}
	else if (type == 2) {
		printf("DFS deque 실행\n");
		deque<Location2D> locDeque; // 위치 덱 객체 생성
		Location2D entry(1, 0); // 입구 객체
		locDeque.push_front(entry); // 덱에 입구 위치 삽입
		while (locDeque.empty() == false) { // 덱이 비어있지 않는 동안
			Location2D here = locDeque.front(); // 덱의 front 상단 객체 복사
			locDeque.pop_front(); // 덱 상단 객체 삭제
			int r = here.row, c = here.col;
			printf("(%d,%d) ", r, c);
			if (map[r][c] == 'x') {
				printf(" 미로 탐색 성공\n");
				return;
			}
			else { // 출구가 아니면 현재 위치를
				map[r][c] = '.'; // 현재 위치를 "지나옴" 처리
				if (isValidLoc(r - 1, c)) locDeque.push_front(Location2D(r - 1, c));
				if (isValidLoc(r + 1, c)) locDeque.push_front(Location2D(r + 1, c));
				if (isValidLoc(r, c - 1)) locDeque.push_front(Location2D(r, c - 1));
				if (isValidLoc(r, c + 1)) locDeque.push_front(Location2D(r, c + 1));
			}
		}
		printf("미로탐색실패\n");
	}
	else if (type == 3) {
		printf("BFS deque 실행\n");
		deque<Location2D> locDeque; // 위치 덱 객체 생성
		Location2D entry(1, 0); // 입구 객체
		locDeque.push_front(entry); // 덱에 입구 위치 삽입
		while (locDeque.empty() == false) { // 덱이 비어있지 않는 동안
			Location2D here = locDeque.back(); // 덱의 front 상단 객체 복사
			locDeque.pop_back(); // 덱 상단 객체 삭제
			int r = here.row, c = here.col;
			printf("(%d,%d) ", r, c);
			if (map[r][c] == 'x') {
				printf(" 미로 탐색 성공\n");
				return;
			}
			else { // 출구가 아니면 현재 위치를
				map[r][c] = '.'; // 현재 위치를 "지나옴" 처리
				if (isValidLoc(r - 1, c)) locDeque.push_front(Location2D(r - 1, c));
				if (isValidLoc(r + 1, c)) locDeque.push_front(Location2D(r + 1, c));
				if (isValidLoc(r, c - 1)) locDeque.push_front(Location2D(r, c - 1));
				if (isValidLoc(r, c + 1)) locDeque.push_front(Location2D(r, c + 1));
			}
		}
		printf("미로탐색실패\n");
	}
	else {
		printf("잘못된 입력입니다. 1, 2, 3 중 선택하십시오");
	}
}
