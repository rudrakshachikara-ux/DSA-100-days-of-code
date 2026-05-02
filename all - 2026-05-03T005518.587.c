#include <stdio.h>
#include <stdlib.h>

// Comparator for qsort (sort by position descending)
int cmp(const void *a, const void *b) {
    int *x = (int*)a;
    int *y = (int*)b;
    return y[0] - x[0];  // descending by position
}

int carFleet(int target, int position[], int speed[], int n) {
    // Build array of [position, speed]
    int cars[n][2];
    for (int i = 0; i < n; i++) {
        cars[i][0] = position[i];
        cars[i][1] = speed[i];
    }

    // Sort by position descending
    qsort(cars, n, sizeof(cars[0]), cmp);

    int fleets = 0;
    double prevTime = 0.0;

    for (int i = 0; i < n; i++) {
        double time = (double)(target - cars[i][0]) / cars[i][1];
        if (time > prevTime) {
            fleets++;
            prevTime = time;
        }
        // else: car joins the fleet ahead
    }
    return fleets;
}

int main() {
    int target, n;
    scanf("%d %d", &target, &n);

    int position[n], speed[n];
    for (int i = 0; i < n; i++) scanf("%d", &position[i]);
    for (int i = 0; i < n; i++) scanf("%d", &speed[i]);

    printf("%d\n", carFleet(target, position, speed, n));
    return 0;
}


