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
struct Node* buildTree(int preorder[], int inorder[], int start, int end, int* preIndex) {
    if (start > end) return NULL;

    // Current root from preorder
    int currVal = preorder[*preIndex];
    (*preIndex)++;
    struct Node* node = newNode(currVal);

    // If leaf node
    if (start == end) return node;

    // Find position in inorder
    int pos = search(inorder, start, end, currVal);

    // Build left and right subtrees
    node->left = buildTree(preorder, inorder, start, pos - 1, preIndex);
    node->right = buildTree(preorder, inorder, pos + 1, end, preIndex);

    return node;
}

// Postorder traversal
void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int N;
    scanf("%d", &N);

    int preorder[N], inorder[N];
    for (int i = 0; i < N; i++) scanf("%d", &preorder[i]);
    for (int i = 0; i < N; i++) scanf("%d", &inorder[i]);

    int preIndex = 0;
    struct Node* root = buildTree(preorder, inorder, 0, N - 1, &preIndex);

    postorder(root);
    return 0;
}

