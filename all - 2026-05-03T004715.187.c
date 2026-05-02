#include <stdio.h>
#include <stdlib.h>

// Min-heap utility
void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

void heapifyDown(int heap[], int size, int i) {
    int smallest = i;
    int left = 2*i + 1, right = 2*i + 2;
    if (left < size && heap[left] < heap[smallest]) smallest = left;
    if (right < size && heap[right] < heap[smallest]) smallest = right;
    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(heap, size, smallest);
    }
}

void heapifyUp(int heap[], int i) {
    while (i > 0) {
        int parent = (i-1)/2;
        if (heap[i] < heap[parent]) {
            swap(&heap[i], &heap[parent]);
            i = parent;
        } else break;
    }
}

int heapPop(int heap[], int *size) {
    int root = heap[0];
    heap[0] = heap[--(*size)];
    heapifyDown(heap, *size, 0);
    return root;
}

void heapPush(int heap[], int *size, int val) {
    heap[(*size)++] = val;
    heapifyUp(heap, *size - 1);
}

// Comparator for qsort (sort by start time)
int cmp(const void *a, const void *b) {
    int *x = (int*)a;
    int *y = (int*)b;
    return x[0] - y[0];
}

int minMeetingRooms(int intervals[][2], int n) {
    // Sort by start time
    qsort(intervals, n, sizeof(intervals[0]), cmp);

    int heap[n]; // min-heap for end times
    int heapSize = 0;

    for (int i = 0; i < n; i++) {
        int start = intervals[i][0], end = intervals[i][1];

        // If earliest meeting ended, reuse room
        if (heapSize > 0 && heap[0] <= start) {
            heapPop(heap, &heapSize);
        }
        // Allocate room for current meeting
        heapPush(heap, &heapSize, end);
    }
    return heapSize;
}

int main() {
    int n;
    scanf("%d", &n);
    int intervals[n][2];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i][0], &intervals[i][1]);
    }
    printf("%d\n", minMeetingRooms(intervals, n));
    return 0;
}


