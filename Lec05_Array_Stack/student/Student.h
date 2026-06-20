#pragma
#include <string.h>

const char MAX_STRING = 50;

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
		strcpy_s(name, n); // 문자열 복사 함수
		strcpy_s(dept, d); // 문자열 복사 함수
	}
	void display() {
		printf(" 학번:%-15d 성명:%-10s 학과:%-20s\n", id, name, dept);
	}
};