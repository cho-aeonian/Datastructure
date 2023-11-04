#include <stdio.h>
#include <stdlib.h>
#include<string.h>


#define STACK_SIZE 20

typedef char element;

typedef struct {
	element data[STACK_SIZE];
	int top;
}Stack;

void initStack( Stack *s );
int isFull( Stack *s );
int isEmpty( Stack *s );
void push( Stack *s, element data );
element pop( Stack *s );

int main(){
 	Stack s;
	char str[20];
	
	printf("문자열 입력 : ");
	scanf("%s", str);
	
	initStack(&s);
	
	for(int i=0; i<strlen(str); i++) {
		push(%s, str[i]);
	}
	
	while (!isEmpty(&s)) {
		printf("%c", pop(%s));
	}
	printf("\n");
	
	return 0;
	
}

void initStack( Stack *s ){
	 s->top=-1;
}
int isFull( Stack *s ){
	return s->top == STACK_SIZE - 1; 
}
int isEmpty( Stack *s ){
 return s->top == -1;
}
void push( Stack *s, element c ){
	 if (!isFull(s)) {
		 s-> data[++(s->top)] = c;
	 }
}
element pop( Stack *s ){
	 if (!isEmpty(s)) {
		 return s->data[(s->top)--];
	 }
	else {
		return '\0';
	}
}