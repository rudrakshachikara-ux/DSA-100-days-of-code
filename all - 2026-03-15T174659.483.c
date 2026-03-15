#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for linked list
struct Node {
    int data;
    struct Node* next;
};

// Queue structure with front and rear pointers
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to initialize queue
void initQueue(struct Queue* q) {
    q->front = q->rear = NULL;
}

// Enqueue operation
void enqueue(struct Queue* q, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

// Dequeue operation
int dequeue(struct Queue* q) {
    if (q->front == NULL) {
        return -1; // Queue empty
    }

    struct Node* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return value;
}

int main() {
    int N;
    scanf("%d", &N);

    struct Queue q;
    initQueue(&q);

    char operation[10];
    int value;

    for (int i = 0; i < N; i++) {
        scanf("%s", operation);

        if (strcmp(operation, "ENQUEUE") == 0) {
            scanf("%d", &value);
            enqueue(&q, value);
        } else if (strcmp(operation, "DEQUEUE") == 0) {
            int result = dequeue(&q);
            printf("%d\n", result);
        }
    }

    return 0;
}

