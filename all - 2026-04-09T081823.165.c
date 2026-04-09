#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// DFS function to detect cycle
bool dfs(int node, int parent, int **adj, int *adjSize, bool *visited) {
    visited[node] = true;

    for (int i = 0; i < adjSize[node]; i++) {
        int neighbor = adj[node][i];

        if (!visited[neighbor]) {
            if (dfs(neighbor, node, adj, adjSize, visited))
                return true;
        }
        else if (neighbor != parent) {
            return true; // cycle detected
        }
    }
    return false;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    // Allocate adjacency list
    int **adj = (int **)malloc(V * sizeof(int *));
    int *adjSize = (int *)calloc(V, sizeof(int));

    for (int i = 0; i < V; i++) {
        adj[i] = (int *)malloc(V * sizeof(int)); // max possible neighbors
    }

    // Input edges
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][adjSize[u]++] = v;
        adj[v][adjSize[v]++] = u;
    }

    bool *visited = (bool *)calloc(V, sizeof(bool));

    // Check each component
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, adjSize, visited)) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");

    return 0;
}

