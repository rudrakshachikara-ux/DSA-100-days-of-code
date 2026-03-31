#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Search for index of value in inorder[]
int search(int inorder[], int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val) return i;
    }
    return -1;
}

// Recursive function to build tree
struct Node* buildTree(int inorder[], int postorder[], int start, int end, int* postIndex) {
    if (start > end) return NULL;

    // Current root from postorder
    int currVal = postorder[*postIndex];
    (*postIndex)--;  // move backwards in postorder
    struct Node* node = newNode(currVal);

    // If leaf node
    if (start == end) return node;

    // Find position in inorder
    int pos = search(inorder, start, end, currVal);

    // Build right subtree first (since postorder is left-right-root)
    node->right = buildTree(inorder, postorder, pos + 1, end, postIndex);
    node->left = buildTree(inorder, postorder, start, pos - 1, postIndex);

    return node;
}

// Preorder traversal
void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int N;
    scanf("%d", &N);

    int inorder[N], postorder[N];
    for (int i = 0; i < N; i++) scanf("%d", &inorder[i]);
    for (int i = 0; i < N; i++) scanf("%d", &postorder[i]);

    int postIndex = N - 1;  // start from last element of postorder
    struct Node* root = buildTree(inorder, postorder, 0, N - 1, &postIndex);

    preorder(root);
    return 0;
}

