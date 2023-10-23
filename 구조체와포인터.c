#include<stdio.h>
#include<string.h>
#define NUM 3

// 구조체 정의
typedef struct Person {
    char name[10];
    int age;
} PERSON;

void inputData(PERSON *p);
void outputData(PERSON *p);

int main() {
    // 구조체 포인터 배열 선언
    PERSON people[NUM];

    // 구조체 포인터 배열로 입력함수 호출
    for (int i = 0; i < NUM; i++) {
        inputData(&people[i]);
    }

    // 구조체 포인터 배열로 출력함수 호출
    for (int i = 0; i < NUM; i++) {
        outputData(&people[i]);
    }

    return 0;
}

void inputData(PERSON *p) {
    // 구조체포인터 변수에 입력
    scanf("%s %d", p->name, &p->age);
}

void outputData(PERSON *p) {
    // 구조체포인터 변수에 출력
    printf("%s, %d\n", p->name, p->age);
}