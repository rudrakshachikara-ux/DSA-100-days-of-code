#include <stdio.h>
#include <stdlib.h>

// Define a node in the BST
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

// Insert a key into the BST
struct Node* insert(struct Node* root, int key) {
    if (root == NULL) {
        return newNode(key);
    }
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    return root;
}

// Iterative search for a key in the BST
int searchIterative(struct Node* root, int key) {
    while (root != NULL) {
        if (root->key == key) {
            return 1; // Found
        } else if (key < root->key) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return 0; // Not found
}

// Driver code
int main() {
    struct Node* root = NULL;
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(values) / sizeof(values[0]);

    // Build BST
    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    // Search examples
    int target1 = 40;
    int target2 = 25;

    if (searchIterative(root, target1)) {
        printf("%d found in BST\n", target1);
    } else {
        printf("%d not found in BST\n", target1);
    }

    if (searchIterative(root, target2)) {
        printf("%d found in BST\n", target2);
    } else {
        printf("%d not found in BST\n", target2);
    }

    return 0;
}

