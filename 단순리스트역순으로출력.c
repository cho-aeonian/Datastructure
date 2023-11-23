#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
	int data;
	struct Node *next;
}Node;

// 연결 리스트를 순서대로 출력하는 연산
void printList(Node *head){
	Node* p = head;
	while (p != NULL) {
		printf("%d",p->data);
		if (p->next != NULL) {
			printf("->");
		}
		p = p->next;
	}
	printf("\n");
}

// 연결 리스트를 역순으로 연결하는 함수 작성
Node* reverse(Node *head){
	Node* p = head;
	Node* q = NULL;
	Node* r = NULL;
	
	while(p != NULL) {
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}
	return q;
}

// 첫번째 노드로 삽입하는 연산
Node*  insertFirst(Node *head, int data ){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = head;
	return newNode;
}

int main(){
	Node* head = NULL ;
	for(int i=10;i<=50;i+=10){
	 //insertFirst 함수호출
		head = insertFirst(head,i);
		printList(head);
	}
	
	head = reverse(head); //역순으로 연결하는 함수 호출
	printf("역순으로 출력\n");
	printList( head );	
	return 0;
}