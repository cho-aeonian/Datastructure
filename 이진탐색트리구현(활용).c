#include<stdio.h> 
#include<stdlib.h> 

typedef char element;
typedef struct TNode {
	element key;
	struct TNode *left, *right;
	// 구조체 선언
} TNode; 

TNode* search(TNode* node, element key){
	if(node == NULL ) return NULL;
	if(key == node->key) 
		return node;
	else if (key < node->key)
		// 왼쪽 서브트리로 순회
		return search(node->left, key);
	// 오른쪽 서브트리로 순회
	else return search(node->right, key);
}
TNode* newNode(element key){
	TNode* temp = (TNode*)malloc(sizeof(TNode));//노드 동적할당
	temp->key = key;
	temp->left = temp->right = NULL;//;
	return temp;
}
TNode* insertNode(TNode* node, element key){
	//탐색이 실패한 위치에 새로운 노드를 삽입 후 반환
	if ( node == NULL ) return newNode(key);
	//그렇지 않으면 순환적으로 트리를 내려간다.
	else if (key < node->key){ 
		node->left = insertNode(node->left, key);//
	}
	else if (key >node->key) {
		node->right = insertNode(node->right, key);//
	}
	//변경된 루트 포인터 반환
	return node;
}
TNode* minNode(TNode* node){
	TNode* cur = node;
	//맨 왼쪽 최소단말 탐색
	while(cur->left !=NULL){
		cur = cur->left;
	}
	return cur;
}
//이진 탐색트리와 키가 주어지면 키가 저장된 노드를 삭제하고 
//새로운 루트 노드를 반환한다.
TNode* deleteNode(TNode* root, element key){
	if (root == NULL) return root;
	//1.만약 키가 루트보다 작으면 ->왼쪽서브트리
	if ( key < root->key) {
		root->left =  deleteNode(root->left, key);//
	}
	//2.만약 키가 루트보다 크면 -> 오른쪽 서브트리
	else if(key > root->key){
		root->right =  deleteNode(root->right, key);//   
	} 
	//3. 키가 루트와 같으면 노드 삭제
	else {
		//3-1.삭제노드가 단말이거나 하나의 서브트리를 가지는 경우
		if (root->left == NULL){
			TNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL){
			TNode* temp = root->left;
			free(root);
			return temp;
		}
		//3-2.삭제노드가 두개의 서브트리를 가지고 있는 경우
		TNode* temp = minNode(root->right);//22의 주소값
		//중위순회시 후계노드 복사
		root->key =  temp->key;//22
		//중위순회시 후계 노드 삭제
		root->right = deleteNode(root->right, temp->key); //26주소 ,22
	}
	return root;
}
void inorder(TNode* root){
	if (root != NULL){
		inorder(root->left);
		///왼쪽서브트리 순회
		printf("[%c] ",root->key);//root 노드방문 출력
		///오른쪽서브트리 순회
		inorder(root->right);
	}
}
void menu(){
	printf("\n*-----------------------*\n");
	printf("\n\t1 : 트리 출력\n");
	printf("\n\t2 : 문자 삽입\n");
	printf("\n\t3 : 문자 삭제\n");
	printf("\n\t4 : 문자 검색\n");
	printf("\n\t5 : 종료\n");
	printf("\n*-----------------------*\n");
	printf("\n메뉴 입력 >> ");

}
int main() 
{    
	TNode* root = NULL;     
	TNode* foundedNode = NULL; 
	char choice, key;          

	root = insertNode(root,'G');
	insertNode(root,'I');
	insertNode(root,'H');
	insertNode(root,'D');
	insertNode(root,'B');
	insertNode(root,'M');
	insertNode(root,'N');
	insertNode(root,'A');
	insertNode(root,'J');
	insertNode(root,'E');
	insertNode(root,'Q');
	
	while( 1 ){
		menu();
		scanf(" %c", &choice);
		switch( choice - '0'){
			case 1 : printf("\n[이진 트리 출력] ");
				//탐색(출력)함수 ;
				inorder(root);
				printf("\n");
				break;
			case 2 : printf("삽입할 문자를 입력하세요 : ");
				scanf(" %c", &key);
				// 탐색함수 호출.
				foundedNode = search(root, key);
				if(foundedNode)
					printf("\n이미 같은 키가 있습니다!\n");
				else
					// 삽입함수 호출;
					root = insertNode(root, key);
				break;
			case 3 : printf("삭제할 문자를 입력하세요 : ");
				scanf(" %c", &key);
				// 탐색 함수 호출
				foundedNode = search(root, key);
				if(!foundedNode)
					printf("\n찾는 키가 이진 트리에 없습니다!!\n");
				else
					// 삭제함수 호출
					root = deleteNode(root, key);
				break;
			case 4 : printf("찾을 문자를 입력하세요 : ");
				scanf(" %c", &key);
				foundedNode = search(root, key);//탐색함수 호출
				if(foundedNode)
					printf("\n%c를 찾았습니다!\n", foundedNode->key);
				else printf("\n문자를 찾지 못했습니다.\n");
				break;
			case 5 : return 0;
			default : printf("없는 메뉴입니다. 메뉴를 다시 선택하세요!\n");
				break;
		}
	}
}