#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int isPossible(int books[], int n, int m, int mid) {
    int students = 1, sum = 0;
    for (int i = 0; i < n; i++) {
        if (sum + books[i] > mid) {
            students++;
            sum = books[i];
            if (students > m) return 0; // not possible
        } else {
            sum += books[i];
        }
    }
    return 1; // possible
}

int allocateBooks(int books[], int n, int m) {
    int low = books[0], high = 0;
    for (int i = 0; i < n; i++) {
        low = max(low, books[i]);
        high += books[i];
    }

    int ans = high;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (isPossible(books, n, m, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int *books = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &books[i]);

    printf("%d\n", allocateBooks(books, n, m));
    free(books);
    return 0;
}



