#include <stdio.h>
#include <stdlib.h>
int *stack;       
int capacity = 2; 
int top = -1;
void resize() { 
    capacity *= 2;
    stack = realloc(stack, capacity * sizeof(int));
    if (stack == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
}
void push(int value) {
    if (top == capacity - 1) {
        resize();
    }
    stack[++top] = value;
}
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("%d\n", stack[top--]);
    }
}
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        for (int i = top; i >= 0; i--) {
            printf("%d", stack[i]);
            if (i != 0) printf(" ");
        }
        printf("\n");
    }
}
int main() {
    int n, op, value;
    scanf("%d", &n);
    stack = malloc(capacity * sizeof(int));
    if (stack == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d", &value);
            push(value);
        } else if (op == 2) {
            pop();
        } else if (op == 3) {
            display();
        }
    }
    free(stack);
    return 0;
}