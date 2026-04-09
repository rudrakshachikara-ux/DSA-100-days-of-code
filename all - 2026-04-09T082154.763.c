#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// DFS function
bool dfs(int node, int **adj, int *adjSize, bool *visited, bool *recStack) {
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < adjSize[node]; i++) {
        int neighbor = adj[node][i];

        if (!visited[neighbor]) {
            if (dfs(neighbor, adj, adjSize, visited, recStack))
                return true;
        }
        else if (recStack[neighbor]) {
            return true; // cycle detected
        }
    }

    recStack[node] = false; // backtrack
    return false;
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
    bool *recStack = (bool *)calloc(V, sizeof(bool));

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, adjSize, visited, recStack)) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    return 0;
}

