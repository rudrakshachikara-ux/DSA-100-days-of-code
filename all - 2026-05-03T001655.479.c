#include <stdio.h>
#include <limits.h>

// Function to check if boards can be painted with max workload 'mid'
int isPossible(int boards[], int n, int k, int mid) {
    int painters = 1;
    int currSum = 0;

    for (int i = 0; i < n; i++) {
        if (boards[i] > mid) return 0;  // single board exceeds limit
        if (currSum + boards[i] <= mid) {
            currSum += boards[i];
        } else {
            painters++;
            currSum = boards[i];
            if (painters > k) return 0;
        }
    }
    return 1;
}

// Function to compute minimum time
int minTime(int boards[], int n, int k) {
    int lo = boards[0], hi = 0;
    for (int i = 0; i < n; i++) {
        if (boards[i] > lo) lo = boards[i]; // largest board
        hi += boards[i];                    // sum of all boards
    }

    int ans = hi;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (isPossible(boards, n, k, mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int boards[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
    }
    printf("%d\n", minTime(boards, n, k));
    return 0;
}


