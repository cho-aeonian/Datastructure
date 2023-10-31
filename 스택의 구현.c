#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STACK_SIZE 100

typedef int element; // int를 element로 재정의

typedef struct {
    int top;
    element data[MAX_STACK_SIZE];
} Stack;

Stack s; // Declare a global instance of the Stack structure

void initStack() {
    s.top = -1;
}

bool isEmpty() {
    if (s.top == -1)
        return true;
    return false;
}

bool isFull() {
    if (s.top == MAX_STACK_SIZE - 1)
        return true;
    return false;
}

void push(element item) {
    if (isFull()) {
        printf("스택이 꽉 차있습니다.\n");
        return;
    }
    s.data[++s.top] = item; // You were missing the assignment of 'item'
}

element pop() { // 반환후 제거
    if (isEmpty()) {
        printf("스택이 비어있습니다.\n"); // You were missing '\n'
        return -1; // Return a placeholder value
    }
    return s.data[s.top--];
}

element peek() { // 반환만
    if (isEmpty()) {
        printf("스택이 비어있습니다.\n"); // You were missing '\n'
        return -1; // Return a placeholder value
    }
    return s.data[s.top];
}

int main() {
    initStack(); // Initialize the stack
    push(1);
    push(2);
    push(3);
    printf("%d\n", pop());
    printf("%d\n", peek());
    printf("%d\n", pop());
    printf("%d\n", peek());
    return 0;
}