#include <stdio.h>
#include <stdlib.h>

// Comparator for qsort (sort by start time)
int cmp(const void *a, const void *b) {
    int *x = (int*)a;
    int *y = (int*)b;
    return x[0] - y[0];
}

int main() {
    int n;
    scanf("%d", &n);
    int intervals[n][2];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i][0], &intervals[i][1]);
    }

    // Step 1: Sort by start time
    qsort(intervals, n, sizeof(intervals[0]), cmp);

    // Step 2: Merge intervals
    int merged[n][2];
    int m = 0; // count of merged intervals

    merged[0][0] = intervals[0][0];
    merged[0][1] = intervals[0][1];
    m = 1;

    for (int i = 1; i < n; i++) {
        if (intervals[i][0] <= merged[m-1][1]) {
            // Overlap → extend end time
            if (intervals[i][1] > merged[m-1][1])
                merged[m-1][1] = intervals[i][1];
        } else {
            // No overlap → new interval
            merged[m][0] = intervals[i][0];
            merged[m][1] = intervals[i][1];
            m++;
        }
    }

    // Step 3: Print merged intervals
    for (int i = 0; i < m; i++) {
        printf("%d %d\n", merged[i][0], merged[i][1]);
    }

    return 0;
}


