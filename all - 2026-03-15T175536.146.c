#include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    if (data == -1) return NULL;  // NULL node
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to build tree from level order array
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node** nodes = (struct Node**)malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++) {
        nodes[i] = newNode(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        if (nodes[i] != NULL) {
            int leftIndex = 2 * i + 1;
            int rightIndex = 2 * i + 2;
            if (leftIndex < n) nodes[i]->left = nodes[leftIndex];
            if (rightIndex < n) nodes[i]->right = nodes[rightIndex];
        }
    }

    struct Node* root = nodes[0];
    free(nodes);
    return root;
}

// Inorder traversal
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int N;
    scanf("%d", &N);

    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, N);

    inorder(root);
    printf("\n");

    return 0;
}

