#include <stdio.h>
#include <limits.h>

#define MAXN 1000   // maximum number of nodes

int adj[MAXN][MAXN];   // adjacency matrix

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize adjacency matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            adj[i][j] = 0;
        }
    }

    // Read edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w;  // undirected graph
    }

    int key[MAXN], visited[MAXN];
    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    key[1] = 0;  // start from node 1
    int totalWeight = 0;

    // Prim’s algorithm
    for (int count = 1; count <= n; count++) {
        int u = -1;
        int minKey = INT_MAX;

        // Pick the unvisited node with smallest key
        for (int v = 1; v <= n; v++) {
            if (!visited[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        visited[u] = 1;
        totalWeight += key[u];

        // Update neighbors
        for (int v = 1; v <= n; v++) {
            if (adj[u][v] && !visited[v] && adj[u][v] < key[v]) {
                key[v] = adj[u][v];
            }
        }
    }

    printf("%d\n", totalWeight);
    return 0;
}


