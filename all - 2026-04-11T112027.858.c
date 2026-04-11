#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXV 1000   // maximum number of vertices

// Structure for adjacency list node
typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

// Structure for adjacency list
typedef struct {
    Node* head;
} AdjList;

// Graph structure
typedef struct {
    int V;
    AdjList* array;
} Graph;

// Min-Heap node
typedef struct {
    int v;
    int dist;
} HeapNode;

// Min-Heap structure
typedef struct {
    int size;
    int capacity;
    int *pos;
    HeapNode **array;
} MinHeap;

// Utility: create new adjacency node
Node* newNode(int v, int w) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->vertex = v;
    node->weight = w;
    node->next = NULL;
    return node;
}

// Utility: create graph
Graph* createGraph(int V) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->V = V;
    graph->array = (AdjList*) malloc(V * sizeof(AdjList));
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;
    return graph;
}

// Add edge (u → v with weight w)
void addEdge(Graph* graph, int u, int v, int w) {
    Node* node = newNode(v, w);
    node->next = graph->array[u].head;
    graph->array[u].head = node;
}

// Create heap node
HeapNode* newHeapNode(int v, int dist) {
    HeapNode* hn = (HeapNode*) malloc(sizeof(HeapNode));
    hn->v = v;
    hn->dist = dist;
    return hn;
}

// Create min-heap
MinHeap* createMinHeap(int capacity) {
    MinHeap* mh = (MinHeap*) malloc(sizeof(MinHeap));
    mh->pos = (int*) malloc(capacity * sizeof(int));
    mh->size = 0;
    mh->capacity = capacity;
    mh->array = (HeapNode**) malloc(capacity * sizeof(HeapNode*));
    return mh;
}

// Swap two heap nodes
void swapHeapNode(HeapNode** a, HeapNode** b) {
    HeapNode* t = *a;
    *a = *b;
    *b = t;
}

// Heapify at index
void minHeapify(MinHeap* mh, int idx) {
    int smallest = idx;
    int left = 2*idx + 1;
    int right = 2*idx + 2;

    if (left < mh->size && mh->array[left]->dist < mh->array[smallest]->dist)
        smallest = left;

    if (right < mh->size && mh->array[right]->dist < mh->array[smallest]->dist)
        smallest = right;

    if (smallest != idx) {
        HeapNode* smallestNode = mh->array[smallest];
        HeapNode* idxNode = mh->array[idx];

        mh->pos[smallestNode->v] = idx;
        mh->pos[idxNode->v] = smallest;

        swapHeapNode(&mh->array[smallest], &mh->array[idx]);
        minHeapify(mh, smallest);
    }
}

// Extract min node
HeapNode* extractMin(MinHeap* mh) {
    if (mh->size == 0) return NULL;

    HeapNode* root = mh->array[0];
    HeapNode* lastNode = mh->array[mh->size - 1];
    mh->array[0] = lastNode;

    mh->pos[root->v] = mh->size - 1;
    mh->pos[lastNode->v] = 0;

    --mh->size;
    minHeapify(mh, 0);

    return root;
}

// Decrease key
void decreaseKey(MinHeap* mh, int v, int dist) {
    int i = mh->pos[v];
    mh->array[i]->dist = dist;

    while (i && mh->array[i]->dist < mh->array[(i-1)/2]->dist) {
        mh->pos[mh->array[i]->v] = (i-1)/2;
        mh->pos[mh->array[(i-1)/2]->v] = i;
        swapHeapNode(&mh->array[i], &mh->array[(i-1)/2]);
        i = (i-1)/2;
    }
}

// Check if heap is empty
int isEmpty(MinHeap* mh) {
    return mh->size == 0;
}

// Dijkstra’s algorithm
void dijkstra(Graph* graph, int src) {
    int V = graph->V;
    int dist[V];

    MinHeap* mh = createMinHeap(V);

    for (int v = 0; v < V; ++v) {
        dist[v] = INT_MAX;
        mh->array[v] = newHeapNode(v, dist[v]);
        mh->pos[v] = v;
    }

    mh->array[src] = newHeapNode(src, dist[src] = 0);
    mh->pos[src] = src;
    mh->size = V;

    while (!isEmpty(mh)) {
        HeapNode* minNode = extractMin(mh);
        int u = minNode->v;

        Node* crawl = graph->array[u].head;
        while (crawl != NULL) {
            int v = crawl->vertex;
            if (mh->pos[v] < mh->size && dist[u] != INT_MAX &&
                crawl->weight + dist[u] < dist[v]) {
                dist[v] = dist[u] + crawl->weight;
                decreaseKey(mh, v, dist[v]);
            }
            crawl = crawl->next;
        }
    }

    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}

// Example usage
int main() {
    int V = 5;
    Graph* graph = createGraph(V);
    addEdge(graph, 0, 1, 9);
    addEdge(graph, 0, 2, 6);
    addEdge(graph, 0, 3, 5);
    addEdge(graph, 0, 4, 3);
    addEdge(graph, 2, 1, 2);
    addEdge(graph, 2, 3, 4);

    dijkstra(graph, 0);

    return 0;
}

