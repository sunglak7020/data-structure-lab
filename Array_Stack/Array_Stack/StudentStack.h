#pragma
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_STRING = 100;
const int MAX_STACK_SIZE = 20; //스택 최대크기

class Student {
	int id; // 학번
	char name[MAX_STRING]; // 이름
	char dept[MAX_STRING]; // 소속 학과
public:
	Student(int i = 0, const char* n = "", const char* d = "") {
		set(i, n, d
		);
	}
	void set(int i, const char* n, const char* d) {
		id = i;
		strcpy(name, n); // 문자열 복사 함수
		strcpy(dept, d); // 문자열 복사 함수
	}
	void display() {
		printf(" 학번:%-15d 성명:%-10s 학과:%-20s\n", id, name, dept);
	}
};

class StudentStack {
	int top; //요소의 개수
	int data[MAX_STACK_SIZE];

public:
	StudentStack() { top = -1; }
	~StudentStack() {}
	bool isEmpty() { return top == -1; }
	bool isFull() { return top == MAX_STACK_SIZE - 1; }

	inline void error(const char* message) {
		printf("%s\n", message);
		exit(1);
	}

	void push(int e) { // 맨 위에 항목 삽입

		if (isFull()) error("스택 공백 에러");
		data[++top] = e;
	}

	int pop() { // 삭제하지 않고 요소 반환
		if (isEmpty()) error("스택 공백 에러");
		return data[top];
	}

	int peek() { // 삭제하지 않고 요소 반환
		if (isEmpty()) error("스택 공백 에러");
		return data[top];
	}

	void display() { // 스택 내용을 화면에 출력
		printf("[스택 항목의 수 = %2d] ==> ", top + 1);
		for (int i = 0; i <= top; i++)
			printf("<%2d>", data[i]);
		printf("\n");
	}

};