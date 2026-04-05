#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Queue implementation
typedef struct {
    int *data;
    int front, rear, size, capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->capacity = capacity;
    q->front = q->size = 0;
    q->rear = capacity - 1;
    q->data = (int*)malloc(capacity * sizeof(int));
    return q;
}

bool isEmpty(Queue* q) {
    return q->size == 0;
}

void enqueue(Queue* q, int item) {
    q->rear = (q->rear + 1) % q->capacity;
    q->data[q->rear] = item;
    q->size++;
}

int dequeue(Queue* q) {
    int item = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return item;
}

// BFS function
void bfs(int n, int adj[][n], int s) {
    bool visited[n];
    for (int i = 0; i < n; i++) visited[i] = false;

    Queue* q = createQueue(n);
    visited[s] = true;
    enqueue(q, s);

    printf("BFS Traversal: ");
    while (!isEmpty(q)) {
        int u = dequeue(q);
        printf("%d ", u);

        for (int v = 0; v < n; v++) {
            if (adj[u][v] && !visited[v]) {
                visited[v] = true;
                enqueue(q, v);
            }
        }
    }
    printf("\n");
    free(q->data);
    free(q);
}

// Example usage
int main() {
    int n = 5;
    int adj[5][5] = {
        {0,1,1,0,0}, // neighbors of 0
        {1,0,0,1,0}, // neighbors of 1
        {1,0,0,1,1}, // neighbors of 2
        {0,1,1,0,0}, // neighbors of 3
        {0,0,1,0,0}  // neighbors of 4
    };
    int source = 0;

    bfs(n, adj, source);
    return 0;
}

