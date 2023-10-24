#include <stdio.h>
#include <stdlib.h>
//예제와 같이 입력한 결과값은?
typedef struct {
            char name[20];
            int* p;
}data;
int main(){
    int n = 50;
    data d1;
    data* d2 = (data*)malloc(sizeof(data));
    d1.p = &n;
    d2->p = &n;
    printf("%d\n", *d1.p + *d2->p);//멤버변수(p) 역참조 
    strcpy(d2->name,"bobby");
    printf("%s\n",(*d2).name); // 구조체변수 d2 역참조 == d2->name
//구조체변수 d2 역참조하여 멤버변수 p역참조 == *d2->p
    printf("%d\n",*(*d2).p);

    free(d2);
    return 0;
}