#include <stdio.h>
#include <stdlib.h>

#define MAX 1000   // maximum heap size

int heap[MAX];
int heapSize = 0;

// Helper functions
int parent(int i) { return (i - 1) / 2; }
int leftChild(int i) { return (2 * i + 1); }
int rightChild(int i) { return (2 * i + 2); }

// Swap utility
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up (for insert)
void heapifyUp(int i) {
    while (i != 0 && heap[parent(i)] > heap[i]) {
        swap(&heap[parent(i)], &heap[i]);
        i = parent(i);
    }
}

// Heapify down (for extractMin)
void heapifyDown(int i) {
    int smallest = i;
    int left = leftChild(i);
    int right = rightChild(i);

    if (left < heapSize && heap[left] < heap[smallest])
        smallest = left;
    if (right < heapSize && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// Insert element
void insert(int x) {
    if (heapSize == MAX) {
        printf("-1\n"); // heap full
        return;
    }
    heap[heapSize] = x;
    heapifyUp(heapSize);
    heapSize++;
}

// Peek (minimum element)
void peek() {
    if (heapSize == 0) {
        printf("-1\n");
    } else {
        printf("%d\n", heap[0]);
    }
}

// Extract minimum element
void extractMin() {
    if (heapSize == 0) {
        printf("-1\n");
        return;
    }
    int min = heap[0];
    heap[0] = heap[heapSize - 1];
    heapSize--;
    heapifyDown(0);
    printf("%d\n", min);
}

// Driver
int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        char op[20];
        scanf("%s", op);

        if (strcmp(op, "insert") == 0) {
            int x;
            scanf("%d", &x);
            insert(x);
        } else if (strcmp(op, "extractMin") == 0) {
            extractMin();
        } else if (strcmp(op, "peek") == 0) {
            peek();
        }
    }

    return 0;
}
