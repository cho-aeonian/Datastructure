#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct Node { 	// 노드 타입
	element data;
	struct Node *next;
} Node;
Node* insertFirst(Node *head, element value)
{
	Node *newNode = (Node*)malloc(sizeof(Node));//(1)동적할당
	newNode->data = value;// (2) 값저장
	newNode->next = head;//(3)헤드 포인터의 값을 복사
	head = newNode;//(4)헤드 포인터 변경
	return head;// 변경된 헤드 포인터 반환
}

// 노드 pre 뒤에 새로운 노드 삽입
Node*  insert(Node *head,Node *pre, element value)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = value;
	newNode->next = pre->next;
	pre->next = newNode;
	return head;
}

Node* deleteFirst(Node *head, Node *pre)
{
	if (head==NULL)
		return NULL;
	Node *temp = pre->next;
	pre->next = temp->next;
	free(temp);
	return head;
}
// pre가 가리키는 노드의 다음 노드를 삭제한다. 
Node* delete(Node *head, Node *pre)
{
	if (pre == NULL || pre->next == NULL)
		return head;
	Node *temp = pre->next;
	pre->next = temp->next;
	free(temp);
	return head;
}

void printList(Node *head)
{
	Node *current = head;
	while(current != NULL) {
		printf("%d -> ", current->data);
		current = current->next;
	}
	printf("NULL\n");
}
int getSum(Node *head)
{
	int sum = 0;
	Node *current = head;
	while (current != NULL) {
		sum += current->data;
		current = current->next;
	}
	//노드의 데이터를 더하는 코드 작성
	return sum;
}


int main(void)
{
	Node *head = NULL;  //;NULL로 초기화
	int count, data;

	printf("노드의 개수: ");
	scanf("%d", &count);
	for (int i = 0; i < count; i++) {
		printf("\n노드 #%d 데이터: ", i+1);
		scanf("%d", &data);
		head = insertFirst(head, data);//head 에 insertFirst실행결과 저장
	}
	printf("\n연결 리스트 데이터의 합 : %d \n",getSum(head));
	
	Node *current = head;
	while (current != NULL) {
		Node *temp = current;
		current = current->next;
		free(temp);
	}
	return 0;
}