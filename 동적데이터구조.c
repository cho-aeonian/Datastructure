// 함수를 활용해 node 동적으로 생성하기
#include<stdio.h>
#include<stdlib.h>
typedef int element;
typedef struct Node {
    element data;
    struct Node* next;
}Node;
Node *createNode( element data );
void printAll( Node *ptr );

int main(){
	Node *head, *node1,*node2 ;
	head = createNode(12);
	node1 = createNode(99);
	node2 = createNode(37);//heard, node1, node2 노드 생성
	
	head->next = node1;
	node1->next = node2;
	node2->next=NULL;//각 노드->next를 저장
	
	//head 노드를 출력
	printAll(head);
	
	free(head);
	free(node1);
	free(node2);
	
	return 0;
}
Node *createNode( element data){
	Node* new_node=(Node*)malloc(sizeof(Node));//노드 크기 동적 할당
	new_node->data = data;//노드의 데이터 저장
	new_node->next=NULL;//노드->next 참조를 NULL저장
	return new_node;
}

void printAll( Node* ptr ){
	while( ptr ){
		//노드의 데이터 출력
		printf("%d",ptr->data);
		if (ptr->next){//next 노드가 있으면 ->출력
			ptr = ptr->next;
			printf("->");//다음노드의 주소로 저장
				}
		else {
			printf("\n");//노드의 데이터 출력
			break;//프린트 종료
		}
	}
}