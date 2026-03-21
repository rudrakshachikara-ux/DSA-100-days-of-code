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

// Recursive function to calculate height of binary tree
int height(struct Node* root) {
    if (root == NULL) {
        return 0; // Empty tree has height 0
    }
    
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    // Height = 1 + max(left subtree height, right subtree height)
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int main() {
    // Constructing a sample tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Height of tree: %d\n", height(root)); // Expected output: 3

    return 0;
}

