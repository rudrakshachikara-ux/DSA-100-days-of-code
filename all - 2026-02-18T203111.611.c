#include <stdio.h>
void rotateArray(int arr[], int n, int k) {
    k = k % n; 
    int temp[n];
    for (int i = 0; i < k; i++) {
        temp[i] = arr[n - k + i];
    }
    for (int i = 0; i < n - k; i++) {
        temp[k + i] = arr[i];
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", temp[i]);
    }
}
int main() {
    int n, k;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &k);
    rotateArray(arr, n, k);
    return 0;
}


