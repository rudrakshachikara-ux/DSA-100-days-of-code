#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Queue structure
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Initialize queue
void initQueue(struct Queue* q) {
    q->front = q->rear = NULL;
}

// Enqueue operation
void enqueue(struct Queue* q, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (q->front == NULL) {
        q->front = q->rear = newNode;
        q->rear->next = q->front; // circular link
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
        q->rear->next = q->front; // maintain circularity
    }
}

// Dequeue operation
int dequeue(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }

    int value;
    if (q->front == q->rear) { // only one element
        value = q->front->data;
        free(q->front);
        q->front = q->rear = NULL;
    } else {
        struct Node* temp = q->front;
        value = temp->data;
        q->front = q->front->next;
        q->rear->next = q->front; // maintain circularity
        free(temp);
    }
    return value;
}

// Display queue
void display(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = q->front;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != q->front);
    printf("\n");
}

int main() {
    int n, m, i, val;
    struct Queue q;
    initQueue(&q);

    // Input
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(&q, val);
    }

    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        dequeue(&q);
    }

    // Output
    display(&q);

    return 0;
}

