#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct Goods {
    char name[100];
    int price;
    bool limit;
} Goods;

int main() {
    Goods* item1;
    item1 = (Goods*)malloc(sizeof(Goods));
    strcpy(item1->name, "교향곡 전집");
    item1->price = 100000;
    item1->limit = false;
    
    Goods* ptr = item1;
    ptr->limit = true;
    
    if (ptr->limit == true)
        printf("한정판\n");
    else
        printf("일반판\n");

    free(item1);

    return 0;
}