#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Recursive DFS function
void dfs_recursive(int n, int **adj, bool *visited, int node) {
    visited[node] = true;
    printf("%d ", node);  // Print the node as part of traversal

    for (int i = 0; i < n; i++) {
        if (adj[node][i] && !visited[i]) {
            dfs_recursive(n, adj, visited, i);
        }
    }
}

int main() {
    int n, s;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Allocate adjacency matrix
    int **adj = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        adj[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &s);

    bool *visited = (bool *)malloc(n * sizeof(bool));
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    printf("DFS Traversal: ");
    dfs_recursive(n, adj, visited, s);
    printf("\n");

    // Free memory
    for (int i = 0; i < n; i++) {
        free(adj[i]);
    }
    free(adj);
    free(visited);

    return 0;
}

