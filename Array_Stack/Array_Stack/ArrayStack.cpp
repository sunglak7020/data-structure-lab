#include "ArrayStack.h" // ArrayStack 클래스 포함
#include "StudentStack.h"

void main()
{
	StudentStack stack;
	for (int i = 1; i < 10; i++)
		stack.push(i);
	stack.display();
	stack.pop();
	stack.pop();
	stack.pop();
	stack.display();

	printf("\n===========================\n");

	StudentStack stack;
	stack.push(Student(2015130007, "홍길동", "컴퓨터공학과"));
	stack.push(Student(2015130100, "이순신", "기계공학과"));
	stack.push(Student(2015130135, "황희", "법학과"));
	stack.display();
	stack.pop();
	stack.display();

}
