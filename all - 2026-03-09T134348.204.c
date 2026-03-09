#include <stdio.h>

#define MAX 100

int arr[MAX];
int size = 0;

// Insert operation
void insert(int x) {
    if (size == MAX) {
        printf("Queue overflow\n");
        return;
    }
    arr[size++] = x;
}

// Delete operation (remove smallest element)
int delete() {
    if (size == 0) return -1;

    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }

    int deleted = arr[minIndex];

    // Shift elements left
    for (int i = minIndex; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;

    return deleted;
}

// Peek operation (return smallest element)
int peek() {
    if (size == 0) return -1;

    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    return arr[minIndex];
}

int main() {
    int N;
    scanf("%d", &N);

    char op[10];
    int x;

    for (int i = 0; i < N; i++) {
        scanf("%s", op);
        if (op[0] == 'i') { // insert
            scanf("%d", &x);
            insert(x);
        } else if (op[0] == 'd') { // delete
            printf("%d\n", delete());
        } else if (op[0] == 'p') { // peek
            printf("%d\n", peek());
        }
    }

    return 0;
}

