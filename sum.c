#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
typedef struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function to create a new tree node
TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to calculate the sum of all nodes in the binary tree
int sumNodes(TreeNode* root) {
    if (root == NULL) {
        return 0; // Base case: If the tree is empty, the sum is 0
    }

    // Recursively sum the values of the left and right subtrees and add the current node's value
    return sumNodes(root->left) + sumNodes(root->right) + root->value;
}

// Function to free the memory of the binary tree
void freeTree(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Main function to demonstrate the sum calculation
int main() {
    // Create a simple binary tree
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // Calculate and print the sum of all nodes in the tree
    int totalSum = sumNodes(root);
    printf("Sum of all nodes in the binary tree: %d\n", totalSum);

    // Free allocated memory
    freeTree(root);

    return 0;
}
