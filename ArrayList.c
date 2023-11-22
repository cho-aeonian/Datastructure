#include <stdio.h>
#include <stdlib.h>
#define MAX 100 //리스트의 최대크기
typedef int element;

typedef struct {
	element array[MAX];
	int size;
}ArrayList;
//배열리스트 구조체타입 정의

void init(ArrayList* L){ //배열리스트 초기화
	L->size = 0;
}

int isEmpty(ArrayList* L){
	return L->size == 0;
}

int isFull(ArrayList* L){
	return L->size == MAX;
}

element getEntry(ArrayList* L, int pos){
	return L->array[pos];
}

void printList(ArrayList* L){
	int i;
	for (i=0; i<L->size; i++) {
		printf("%d->",L->array[i]);
	}
	printf("\n");
}

void insertLast(ArrayList* L, element item){
	if(isFull(L)) {
		printf("리스트가 가득 찼습니다.\n");
		return;
	}
	L->array[L->size++] = item;
}

void insert(ArrayList* L, int pos, element item){
	int i;
	if (isFull(L)) {
		printf("리스트가 가득 찼습니다.\n");
		return;
	}
	if(pos<0 || pos > L->size) {
		printf("잘못된 위치입니다.\n");
		return;
	}
	for(i=L->size-1; i>=pos; i--) {
		L->array[i+1]=L->array[i];
	}
	L->array[pos] = item;
	L->size++;
}

element delete(ArrayList* L,int pos){
	int i;
	element item;
	if (isEmpty(L)) {
		printf("리스트가 비어 있습니다.\n");
		return -1;
	}
	if(pos<0 || pos>=L->size) {
		printf("잘못된 위치입니다.\n");
		return -1;
	}
	item = L->array[pos];
	for(i=pos; i<L->size-1; i++) {
		L->array[i] = L->array[i+1];
	}
	L->size--;
	return item;
}

int main(){
	ArrayList list;
	init(&list);
	
	insertLast(&list,10);
	printList(&list);
	
	insertLast(&list,20);
	printList(&list);
	
	insertLast(&list,30);
	printList(&list);
	
	insertLast(&list, 40);
	printList(&list);
	
	insert(&list, 2, 100);
	printList(&list);
	
	delete(&list, 1);
	printList(&list);

	return 0;
}