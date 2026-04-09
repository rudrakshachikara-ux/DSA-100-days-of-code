#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// DFS function
void dfs(int node, int **adj, int *adjSize, bool *visited, int *stack, int *top) {
    visited[node] = true;

    for (int i = 0; i < adjSize[node]; i++) {
        int neighbor = adj[node][i];

        if (!visited[neighbor]) {
            dfs(neighbor, adj, adjSize, visited, stack, top);
        }
    }

    stack[(*top)++] = node; // push to stack
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    int **adj = (int **)malloc(V * sizeof(int *));
    int *adjSize = (int *)calloc(V, sizeof(int));

    for (int i = 0; i < V; i++) {
        adj[i] = (int *)malloc(V * sizeof(int));
    }

    // Input directed edges
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][adjSize[u]++] = v;
    }

    bool *visited = (bool *)calloc(V, sizeof(bool));
    int *stack = (int *)malloc(V * sizeof(int));
    int top = 0;

    // DFS for all nodes
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, adj, adjSize, visited, stack, &top);
        }
    }

    // Print topological order (reverse stack)
    for (int i = top - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}

