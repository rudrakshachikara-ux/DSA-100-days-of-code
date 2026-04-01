#include <stdio.h>

int isMinHeap(int arr[], int n) {
    // Check heap property for all non-leaf nodes
    for (int i = 0; i <= (n - 2) / 2; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[i] > arr[left]) {
            return 0; // Not a min-heap
        }
        if (right < n && arr[i] > arr[right]) {
            return 0; // Not a min-heap
        }
    }
    return 1; // Valid min-heap
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (isMinHeap(arr, n))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}

