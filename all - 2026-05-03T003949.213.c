#include <stdio.h>

// Insertion sort for individual buckets
void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Bucket Sort function
void bucketSort(float arr[], int n) {
    // Step 1: Create n empty buckets
    float buckets[n][n];   // each bucket can hold up to n elements
    int bucketCount[n];    // track number of elements in each bucket

    for (int i = 0; i < n; i++)
        bucketCount[i] = 0;

    // Step 2: Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int bi = (int)(n * arr[i]);  // bucket index
        buckets[bi][bucketCount[bi]++] = arr[i];
    }

    // Step 3: Sort each bucket
    for (int i = 0; i < n; i++) {
        if (bucketCount[i] > 0)
            insertionSort(buckets[i], bucketCount[i]);
    }

    // Step 4: Concatenate buckets back into arr[]
    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucketCount[i]; j++) {
            arr[idx++] = buckets[i][j];
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    bucketSort(arr, n);

    // Print sorted array
    for (int i = 0; i < n; i++) {
        printf("%.4f ", arr[i]);  //
 }
    return 0;
}
