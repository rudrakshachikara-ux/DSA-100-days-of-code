#include <stdio.h>
#include <stdlib.h>
struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};
struct Queue {
    struct Node** arr;
    int front, rear, size, capacity;
};
struct Queue* createQueue(int capacity) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->capacity = capacity;
    q->front = q->size = 0;
    q->rear = capacity - 1;
    q->arr = (struct Node**)malloc(capacity * sizeof(struct Node*));
    return q;
}
int isEmpty(struct Queue* q) { return q->size == 0; }
void enqueue(struct Queue* q, struct Node* item) {
    if (q->size == q->capacity) return;
    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = item;
    q->size++;
}
struct Node* dequeue(struct Queue* q) {
    if (isEmpty(q)) return NULL;
    struct Node* item = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return item;
}

// Create new node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Build tree from level order input
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* root = newNode(arr[0]);
    struct Queue* q = createQueue(n);
    enqueue(q, root);
    int i = 1;
    while (!isEmpty(q) && i < n) {
        struct Node* curr = dequeue(q);
        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            enqueue(q, curr->left);
        }
        i++;
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            enqueue(q, curr->right);
        }
        i++;
    }
    return root;
}

// Zigzag traversal
void zigzagTraversal(struct Node* root) {
    if (!root) return;
    struct Queue* q = createQueue(1000);
    enqueue(q, root);
    int leftToRight = 1;
    while (!isEmpty(q)) {
        int levelSize = q->size;
        int* level = (int*)malloc(levelSize * sizeof(int));
        for (int i = 0; i < levelSize; i++) {
            struct Node* node = dequeue(q);
            level[i] = node->val;
            if (node->left) enqueue(q, node->left);
            if (node->right) enqueue(q, node->right);
        }
        if (leftToRight) {
            for (int i = 0; i < levelSize; i++) printf("%d ", level[i]);
        } else {
            for (int i = levelSize - 1; i >= 0; i--) printf("%d ", level[i]);
        }
        leftToRight = !leftToRight;
        free(level);
    }
}

int main() {
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
    struct Node* root = buildTree(arr, N);
    zigzagTraversal(root);
    return 0;
}

