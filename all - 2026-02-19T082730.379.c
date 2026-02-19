#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
void closestToZeroPair(int arr[], int n) {
    qsort(arr, n, sizeof(int), compare);
    int left = 0, right = n - 1;
    int minSum = INT_MAX;
    int bestLeft = left, bestRight = right;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (abs(sum) < abs(minSum)) {
            minSum = sum;
            bestLeft = left;
            bestRight = right;
        }
        if (sum < 0)
            left++;
        else
            right--;
    }
    printf("%d %d\n", arr[bestLeft], arr[bestRight]);
}
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    closestToZeroPair(arr, n);
    return 0;
}


