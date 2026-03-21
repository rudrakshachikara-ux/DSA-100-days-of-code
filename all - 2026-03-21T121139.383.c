#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Recursive function to count leaf nodes
int countLeafNodes(struct Node* root) {
    if (root == NULL) {
        return 0; // Empty tree has 0 leaf nodes
    }
    if (root->left == NULL && root->right == NULL) {
        return 1; // This node is a leaf
    }
    // Count leaves in left and right subtrees
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    // Constructing a sample tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Number of leaf nodes: %d\n", countLeafNodes(root)); // Expected output: 3

    return 0;
}

