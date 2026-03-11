#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure for doubly linked list
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Deque structure
typedef struct Deque {
    Node* front;
    Node* rear;
    int size;
} Deque;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Initialize deque
Deque* createDeque() {
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    dq->front = dq->rear = NULL;
    dq->size = 0;
    return dq;
}

// Push at front
void push_front(Deque* dq, int value) {
    Node* newNode = createNode(value);
    if (dq->front == NULL) {
        dq->front = dq->rear = newNode;
    } else {
        newNode->next = dq->front;
        dq->front->prev = newNode;
        dq->front = newNode;
    }
    dq->size++;
}

// Push at back
void push_back(Deque* dq, int value) {
    Node* newNode = createNode(value);
    if (dq->rear == NULL) {
        dq->front = dq->rear = newNode;
    } else {
        newNode->prev = dq->rear;
        dq->rear->next = newNode;
        dq->rear = newNode;
    }
    dq->size++;
}

// Pop from front
void pop_front(Deque* dq) {
    if (dq->front == NULL) {
        printf("Deque is empty!\n");
        return;
    }
    Node* temp = dq->front;
    dq->front = dq->front->next;
    if (dq->front) dq->front->prev = NULL;
    else dq->rear = NULL;
    free(temp);
    dq->size--;
}

// Pop from back
void pop_back(Deque* dq) {
    if (dq->rear == NULL) {
        printf("Deque is empty!\n");
        return;
    }
    Node* temp = dq->rear;
    dq->rear = dq->rear->prev;
    if (dq->rear) dq->rear->next = NULL;
    else dq->front = NULL;
    free(temp);
    dq->size--;
}

// Get front element
int front(Deque* dq) {
    if (dq->front == NULL) {
        printf("Deque is empty!\n");
        return -1;
    }
    return dq->front->data;
}

// Get rear element
int back(Deque* dq) {
    if (dq->rear == NULL) {
        printf("Deque is empty!\n");
        return -1;
    }
    return dq->rear->data;
}

// Check if empty
bool empty(Deque* dq) {
    return dq->size == 0;
}

// Get size
int size(Deque* dq) {
    return dq->size;
}

// Clear deque
void clear(Deque* dq) {
    while (!empty(dq)) {
        pop_front(dq);
    }
}

// Print deque (for debugging)
void printDeque(Deque* dq) {
    Node* temp = dq->front;
    printf("Deque: ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Example usage
int main() {
    Deque* dq = createDeque();

    push_back(dq, 10);
    push_front(dq, 20);
    push_back(dq, 30);
    printDeque(dq);   // Output: 20 10 30

    pop_front(dq);
    printDeque(dq);   // Output: 10 30

    pop_back(dq);
    printDeque(dq);   // Output: 10

    printf("Front: %d\n", front(dq)); // 10
    printf("Back: %d\n", back(dq));   // 10
    printf("Size: %d\n", size(dq));   // 1
    printf("Empty: %s\n", empty(dq) ? "Yes" : "No");

    clear(dq);
    printDeque(dq);   // Output: Deque:

    return 0;
}