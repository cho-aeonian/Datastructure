#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>
typedef struct {
    char word[100];
    char meaning[200];
}element;
typedef struct TNode{
    element key;
    struct TNode *left, *right;
}TNode;
int compare(element e1, element e2){
    return strcmp(e1.word,e2.word); //e1<e2:-1,==:0,>1
}
//이진탐색트리 출력함수
void display(TNode* p){
    if(!p) return;
    display(p->left);
    printf("(%s:%s)",p->key.word,p->key.meaning);
    display(p->right);
}
//이진탐색트리 탐색함수
TNode* search(TNode* root, element key){
    TNode *p = root;
    while(p) {
        if (compare(key,p->key)==0)
            break;
        else if (compare(key,p->key) > 0)
            p = p->right;
        else if (compare(key,p->key) < 0)
            p = p->left;
    }
    return p;
}
TNode* new_node(element item){
    TNode *node = (TNode*)malloc(sizeof(TNode));
    strcpy(node->key.word,item.word);
    strcpy(node->key.meaning,item.meaning);
    node->left = node->right = NULL;

    return node;
}

TNode* insert_node(TNode* root, element key){
    //트리가 공백이면 새로운 노드를 반환
    if(!root)
        return new_node(key);
    //순환적으로 트리를 내려가서 삽입
    if(compare(key,root->key) < 0) {
        root->left = insert_node(root->left,key);
    }
    else if(compare(key,root->key) > 0) {
        root->right = insert_node(root->right,key);
    }
    return root;
}

TNode* minNode(TNode* node){
    TNode* current = node;
    //맨왼쪽 단말노드를 찾으러 내려감
    while (current->left != NULL)
        current = current->left;
    return current;
}

//이진 탐색 트리와 키가 주어지면 키가 저장된 노드를 삭제하고 새로운 루트노드반환
TNode* deleteNode(TNode* root, element key){
    if (root == NULL) return root;
    //1.만약 키가 루트보다 작으면 ->왼쪽서브트리
    if ( compare(key, root->key) < 0) {
        root->left = deleteNode(root->left, key);//
    }
    //2.만약 키가 루트보다 크면 -> 오른쪽 서브트리
    else if(compare(key, root->key) > 0){
        root->right = deleteNode(root->right, key);//    
    }
    //3. 키가 루트와 같으면 노드 삭제
    else if(compare(key, root->key) == 0){
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
        TNode* temp = minNode(root->right);// //22의 주소값
        //중위순회시 후계노드 복사
        root->key = temp->key; //22
        //중위순회시 후계 노드 삭제
        root->right = deleteNode(root->right,temp->key); //26주소 ,22
    }
    return root;
}



int main(){
    char command;
    element e;
    TNode* root = NULL;
    TNode* tmp;
    do{
        printf("\n ****i: 입력, d: 삭제,s: 탐색,p: 출력,q:종료****:");
        command = getchar();
        getchar();
        switch(command){
            case 'i':
                printf("단어:");
                //단어 한줄 e.word에 입력받음
                gets(e.word);
                printf("의미:");
            //의미 한줄 e.meaning에 입력받음
                gets(e.meaning);
                root = insert_node(root,e); //구조체변수 e입력하는 함수 실행
                break;
            case 'd':
                printf("단어:");
                gets(e.word);
                root = deleteNode(root,e);// 삭제 함수 실행
                break;
            case 's':
                printf("단어:");
                gets(e.word);
                tmp = search(root,e);//탐색함수 실행
                if(tmp !=NULL){
                    printf("의미: %s\n",tmp->key.meaning);
                     
                }
                break;
            case 'p':
                display(root);
                printf("\n");
                break;
        }
    }while(command != 'q');

    return 0;
}