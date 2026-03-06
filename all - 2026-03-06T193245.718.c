#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;
void push(Node** top, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}
int pop(Node** top) {
    if (*top == NULL) {
        printf("Stack underflow\n");
        exit(1);
    }
    Node* temp = *top;
    int value = temp->data;
    *top = temp->next;
    free(temp);
    return value;
}
int evaluatePostfix(char* expr) {
    Node* stack = NULL;
    char* token = strtok(expr, " ");
    while (token != NULL) {
        if (isdigit(token[0])) {
            push(&stack, atoi(token));
        } else {
            int val2 = pop(&stack);
            int val1 = pop(&stack);
            int result;
            switch (token[0]) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
                default:
                    printf("Invalid operator\n");
                    exit(1);
            }
            push(&stack, result);
        }
        token = strtok(NULL, " ");
    }
    return pop(&stack);
}
int main() {
    char expr[100];
    printf("Enter postfix expression: ");
    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = '\0'; // remove newline
    int result = evaluatePostfix(expr);
    printf("Result: %d\n", result);
    return 0;
}

