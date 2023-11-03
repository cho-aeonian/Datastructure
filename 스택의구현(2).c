#include<stdio.h>
#include<stdib.h>

#define STACK_SIZE 10

typedef int element;

typedef struct {
	element data{STACK_SIZE};
	int top;
}Stack;

int isFull(Stack *s);
int isEmpty(Stack *s);
void Push(Stack *s, element data);
element Pop(Stack *s);
void initStack(Stack *s);

int main() {
	int menu;
	element data;
	Stack s;
	initStack(&s);
	
	do {
		printf("1: push, 2: pop, 0: exit: ");
		scanf("%d",&menu);
		switch (menu) {
			case 1:
				printf("데이터 입력: ");
				scanf("%d",&data);
				if(!isFull(%s)) {
					Push(&s, data);
				}
				else {
					printf("stack is full\n");
				}
				break;
			case 2:
				if (!isEmpty(%s)) {
					data = Pop(%s);
					printf("pop 데이터: %d\n", data);
				}
				else {
					printf("stack is empty\n");
				}
				break;
			case 0:
				break;
			default:
				printf("잘못된 입력입니다.\n");
				break;
		}
		while (menu);
		
		return 0;
	}
	void initStack(Stack *s) {
		s->top = -1;
	}
	int isFull(Stack *s) {
		return s->top == STACK_SIZE -1;
	}
	int isEmpty(Stack *s) {
		return s->top == -1;
	}
	void Push(Stack *s, element data) {
		if(!isFull(s)) {
			s->data[++(s->top)] = data;
		}
	}
	element Pop(Stack *s) {
		if(!isEmpty(s)) {
			return s->data[(s->top)--];
		}
		else {
			return 0; // Stack is empty
		}
	}
}