#include <stdio.h>

// Function to compute integer square root using Binary Search
int integerSqrt(int n) {
    if (n == 0 || n == 1) return n;

    int low = 0, high = n, ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (mid <= n / mid) { // avoid overflow: mid*mid <= n
            ans = mid;        // mid is a candidate
            low = mid + 1;    // search right half
        } else {
            high = mid - 1;   // search left half
        }
    }
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d\n", integerSqrt(n));

    return 0;
}


