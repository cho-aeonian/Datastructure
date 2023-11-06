// 수식 괄호 검사
// 소중대 괄호를 사용할 시에 순서대로 맞게 사용했는지 검사하는 알고리즘
#include <stdio.h>
#include <stdlib.h> //C표준 유틸리티 함수들을 모아 놓은 헤더파일
#include<stdbool.h> //논리 자료형으로 참과 거짓을 나타냄

#define STACK_SIZE 20

typedef char element; // char를 스택 element의 자료형으로 정의함

typedef struct {
	element data[STACK_SIZE]; // 스택의 데이터를 저장하는 배열
	int top; // 스택 맨 위 요소의 인덱스
}Stack;

void initStack( Stack *s ); // 스택 초기화 함수
int isFull( Stack *s ); // 스택이 가득 찼는지 확인하는 함수
int isEmpty( Stack *s ); // 스택이 비어 있는지 확인하는 함수
void push( Stack *s, element data ); // 스택에 요소를 푸시하는 함수
element pop( Stack *s ); // 스택에서 요소를 팝하는 함수

int checkExpression(char expr[]);

int main(){
	Stack s; // 스택 선언
	char expr[20]; // 입력 받을 수식을 저장할 배열
	
	printf("괄호포함 수식 입력 : ");
	scanf("%s", expr); // 사용자로부터 수식을 입력 받음
	
	if (checkTest(expr)) printf("성공");
	else printf("실패");
	return 0;
	
}

void initStack( Stack *s ){
	s->top = -1;
} // 스택의 맨 윗 부분을 -1로 초기화하여 비어있음을 표시한다.

int isFull( Stack *s ){
	return s->top == STACK_SIZE -1;
} // 스택이 가득 차 있는지 확인한다.

int isEmpty( Stack *s ){
	return s->top == -1;
} // 스택이 비어 있는지 확인한다.

void push( Stack *s, element c ){
	if(isFull(s)){
		printf("stack is full\n");
		exit(EXIT_FAILURE);
	}
	s->data[++(s->top)]=c;
} // 요소를 스택에 푸시한다.

element pop( Stack *s ){
	if(isEmpty(s)) {
		printf("stack is empty\n");
		exit(EXIT_FAILURE);
	}
	return s->data[(s->top)--];
} // 스택에서 요소를 팝한다.

int checkTest(char expr[]){
	Stack s;
	initStack(&s);
	char ch,open_ch; //
	
  for(int i=0;expr[i]!='\0';i++){
		ch = expr[i];
		switch(ch){
			case '(': 
			case '[':
			case '{':
				push(&s, ch); // 여는 괄호의 스택을 푸시한다.
				break;
				break;
			case ')':
			case ']':
			case '}':	
				if (isEmpty(&s)) return 0; // 스택이 비어 있으면 괄호가 균형을 이루지 않는다.
				open_ch = pop(&s); // 스택의 맨 위 요소를 팝한다.
				
				//팝된 여는 괄호와 닫는 괄호가 일치하는지 확인한다.
				if ((open_ch == '(' && ch != ')') ||
					  (open_ch == '[' && ch != ']') ||
					  (open_ch == '{' && ch != '}') ) {
					return 0; // 괄호가 일치하지 않는다
				}
				break; //
		}
	}
	return isEmpty(&s) ? 1 : 0; // 스택이 비어 있으면 괄호가 균형을 이루지 않는다.
}