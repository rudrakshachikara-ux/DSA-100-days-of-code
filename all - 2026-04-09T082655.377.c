#include <stdio.h>
#include <stdlib.h>

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    int **adj = (int **)malloc(V * sizeof(int *));
    int *adjSize = (int *)calloc(V, sizeof(int));
    int *inDegree = (int *)calloc(V, sizeof(int));

    for (int i = 0; i < V; i++) {
        adj[i] = (int *)malloc(V * sizeof(int));
    }

    // Input directed edges
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][adjSize[u]++] = v;
        inDegree[v]++; // increase in-degree
    }

    // Queue
    int *queue = (int *)malloc(V * sizeof(int));
    int front = 0, rear = 0;

    // Push nodes with in-degree 0
    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int count = 0;

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        count++;

        for (int i = 0; i < adjSize[node]; i++) {
            int neighbor = adj[node][i];
            inDegree[neighbor]--;

            if (inDegree[neighbor] == 0) {
                queue[rear++] = neighbor;
            }
        }
    }

    // If count != V → cycle exists
    if (count != V) {
        printf("\nCycle exists\n");
    }

    return 0;
}

