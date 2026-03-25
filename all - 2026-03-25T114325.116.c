#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Define a Node structure
struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

// Queue structure for BFS
struct QueueNode {
    struct Node* node;
    int hd;  // horizontal distance
    struct QueueNode* next;
};

struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

// Enqueue function
void enqueue(struct Queue* q, struct Node* node, int hd) {
    struct QueueNode* temp = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    temp->node = node;
    temp->hd = hd;
    temp->next = NULL;
    if (!q->rear) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

// Dequeue function
struct QueueNode* dequeue(struct Queue* q) {
    if (!q->front) return NULL;
    struct QueueNode* temp = q->front;
    q->front = q->front->next;
    if (!q->front) q->rear = NULL;
    return temp;
}

// Create new node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Build tree from level-order input
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    struct Queue q = {NULL, NULL};
    enqueue(&q, root, 0);

    int i = 1;
    while (i < n) {
        struct QueueNode* temp = dequeue(&q);
        struct Node* curr = temp->node;

        // Left child
        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            enqueue(&q, curr->left, 0);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            enqueue(&q, curr->right, 0);
        }
        i++;
    }
    return root;
}

// Vertical order traversal
void verticalOrder(struct Node* root) {
    if (!root) return;

    // Dictionary replacement using array of linked lists
    struct Queue q = {NULL, NULL};
    enqueue(&q, root, 0);

    // Track min and max horizontal distance
    int minHD = INT_MAX, maxHD = INT_MIN;

    // Store nodes by HD
    struct Node* nodes[1000][1000]; // simplistic storage
    int count[1000] = {0};

    while (q.front) {
        struct QueueNode* temp = dequeue(&q);
        struct Node* node = temp->node;
        int hd = temp->hd;

        if (hd < minHD) minHD = hd;
        if (hd > maxHD) maxHD = hd;

        nodes[hd + 500][count[hd + 500]++] = node;

        if (node->left) enqueue(&q, node->left, hd - 1);
        if (node->right) enqueue(&q, node->right, hd + 1);

        free(temp);
    }

    // Print nodes column by column
    for (int hd = minHD; hd <= maxHD; hd++) {
        for (int j = 0; j < count[hd + 500]; j++) {
            printf("%d ", nodes[hd + 500][j]->val);
        }
        printf("\n");
    }
}

// -------------------------
// Example usage
int main() {
    int N = 7;
    int arr[] = {1, 2, 3, 4, 5, 6, 7};

    struct Node* root = buildTree(arr, N);
    verticalOrder(root);

    return 0;
}

