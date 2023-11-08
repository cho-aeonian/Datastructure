#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 300

typedef int element;

typedef struct {
    element data[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, element c) {
    if (isFull(s)) {
        printf("Stack is full\n");
        exit(EXIT_FAILURE);
    }
    s->data[++(s->top)] = c;
}

element pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return s->data[(s->top)--];
}

int evaluatePostfix(char expr[]) {
    Stack s;
    initStack(&s);
    int i = 0;

    while (expr[i] != '\0') {
        if (isdigit(expr[i])) {
            int operand = 0;
            while (isdigit(expr[i])) {
                operand = operand * 10 + (expr[i] - '0');
                i++;
            }
            push(&s, operand);
        } else if (expr[i] == ' ') {
            // Skip spaces
            i++;
        } else {
            // Operator encountered
            int operand2 = pop(&s);
            int operand1 = pop(&s);
            switch (expr[i]) {
                case '+':
                    push(&s, operand1 + operand2);
                    break;
                case '-':
                    push(&s, operand1 - operand2);
                    break;
                case '*':
                    push(&s, operand1 * operand2);
                    break;
                case '/':
                    if (operand2 == 0) {
                        printf("Division by zero\n");
                        exit(EXIT_FAILURE);
                    }
                    push(&s, operand1 / operand2);
                    break;
                default:
                    printf("Invalid operator: %c\n", expr[i]);
                    exit(EXIT_FAILURE);
            }
            i++;
        }
    }

    if (isEmpty(&s)) {
        printf("Empty expression\n");
        exit(EXIT_FAILURE);
    }

    return pop(&s);
}

int main() {
    char expr[MAX];
    fgets(expr, sizeof(expr), stdin);

    int result = evaluatePostfix(expr);
    printf("%d\n", result);

    return 0;
}