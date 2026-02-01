#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc((n + 1) * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int pos, x;
    scanf("%d", &pos);
    scanf("%d", &x);
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = x;
    n++; 
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    free(arr); 
    return 0;
}

