#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Adjacency list node
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Graph structure
typedef struct {
    int numVertices;
    Node** adjLists;
    bool* visited;
} Graph;

// Create a node
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create a graph with n vertices
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    graph->adjLists = (Node**)malloc((vertices + 1) * sizeof(Node*));
    graph->visited = (bool*)malloc((vertices + 1) * sizeof(bool));

    for (int i = 1; i <= vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = false;
    }
    return graph;
}

// Add edge (undirected)
void addEdge(Graph* graph, int src, int dest) {
    // src → dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // dest → src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// DFS traversal
void dfs(Graph* graph, int vertex) {
    graph->visited[vertex] = true;
    Node* temp = graph->adjLists[vertex];

    while (temp != NULL) {
        int connectedVertex = temp->vertex;
        if (!graph->visited[connectedVertex]) {
            dfs(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

// Count connected components
int countComponents(Graph* graph) {
    int count = 0;
    for (int v = 1; v <= graph->numVertices; v++) {
        if (!graph->visited[v]) {
            dfs(graph, v);
            count++;
        }
    }
    return count;
}

// Driver
int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Graph* graph = createGraph(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    printf("%d\n", countComponents(graph));

    return 0;
}


