#include<stdio.h>
#include<malloc.h>

typedef struct stackNode {
	int data;
	struct stackNode* link;
	} stackNode;
	
stackNode* top;

void push(int item){
	stackNode* temp = (stackNode*)malloc(sizeof(stackNode));

	temp->data = item;
	temp->link = top;
	top = temp;
}

int pop() {
	int item;
	stackNode* temp = top;
	if (top != NULL) {
		item = temp->data;
		top = temp->link;
		free(temp);
		return item;
	}
}

void printstack() {
	stackNode* p = top;
	printf("\n STACK[");
	while (p) {
		printf("%d", p->data);
		p = p->link;
	}
	printf("]");
}

int main(void) {
	int item;
	top = NULL;
	push(1); printstack();
	push(2); printstack();
	push(3); printstack();
	item = pop();   printstack(); printf("%d\n", item);
	item = pop();   printstack(); printf("%d\n", item);
	getchar(); return 0;
}