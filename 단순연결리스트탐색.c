#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node {
	char data[100];
	struct Node* next;
}Node;

Node* insertFirst(Node* head, char* data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if(newNode==NULL) {
		printf("메모리 할당 오류\n");
		exit(1);
	}
	strcpy(newNode->data, data);
	newNode->next = head;
	return newNode;
}

void printList(Node* head) {
	Node* current = head;
	while(current != NULL) {
		printf("%s->",current->data);
		current = current->next;
	}
	printf("NULL\n");
}

int main() {
	Node* head = NULL;
	Node* p;
	char str[3][10] = {"melon","kiwi","apple"};
	char find[10];
	
	for(int i=0; i<3; i++) {
		head = insertFirst(head, str[i]);
		printList(head);
	}
	
	printf("찾을 데이터를 입력하세요\n");
	scanf("%s",find);
	
	for(p=head; p!=NULL; p = p->next) {
		if(strcmp(p->data, find)==0) {
			printf("%s을 찾았습니다.\n",find);
			break;
		}
	}
	while (head != NULL) {
		Node* temp = head;
		head = head->next;
		free(temp);
	}
	return 0;
}