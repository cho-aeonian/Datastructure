#include <stdio.h>
#include <stdbool.h>
#include <ctype.h> // for tolower()

#define MAX 100

typedef char element;

typedef struct Stack {
    element str[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

bool isFull(Stack *s) {
    return s->top == MAX - 1;
}

bool isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, element c) {
    if (isFull(s)) {
        printf("FULL");
    } else {
        s->str[++(s->top)] = c;
    }
}

element pop(Stack *s) {
    if (isEmpty(s)) {
        printf("EMPTY");
        return 0;
    }
    return s->str[(s->top)--];
}

bool palindrome(char String[]) {
    Stack S;
    initStack(&S);
    int i = 0;
    int length = 0;

    // Calculate the length of the string
    while (String[length] != '\0') {
        length++;
    }

    // Push all characters from the first half of the string to the stack (ignoring case)
    for (i = 0; i < length / 2; i++) {
        char c = tolower(String[i]);
        push(&S, c);
    }

    // Compare characters from the stack with the second half of the string (ignoring case)
    for (i = (length + 1) / 2; i < length; i++) {
        char c = tolower(String[i]);
        if (c != pop(&S)) {
            return false; // Characters do not match, not a palindrome
        }
    }

    // If the stack is empty at this point, it's a palindrome
    return isEmpty(&S);
}

int main(void) {
    char str[MAX];
    scanf("%s", str);

    if (palindrome(str)) {
        printf("TRUE\n");
    } else {
        printf("FALSE\n");
    }
    return 0;
}