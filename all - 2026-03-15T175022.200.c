#include <stdio.h>
#include <stdlib.h>

// Stack implementation using array
struct Stack {
    int top;
    int capacity;
    int* array;
};

// Function to create stack
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(capacity * sizeof(int));
    return stack;
}

// Push operation
void push(struct Stack* stack, int item) {
    stack->array[++stack->top] = item;
}

// Pop operation
int pop(struct Stack* stack) {
    return stack->array[stack->top--];
}

int main() {
    int N;
    scanf("%d", &N);

    int queue[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &queue[i]);
    }

    // Create stack of size N
    struct Stack* stack = createStack(N);

    // Step 1: Push all queue elements into stack
    for (int i = 0; i < N; i++) {
        push(stack, queue[i]);
    }

    // Step 2: Pop all elements from stack back into queue (reversed order)
    for (int i = 0; i < N; i++) {
        queue[i] = pop(stack);
    }

    // Print reversed queue
    for (int i = 0; i < N; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");

    // Free memory
    free(stack->array);
    free(stack);

    return 0;
}

