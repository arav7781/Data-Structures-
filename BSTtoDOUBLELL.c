#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new tree node.
struct TreeNode* newTreeNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to print the doubly linked list.
void printList(struct TreeNode* node) {
    struct TreeNode* last = NULL;
    printf("Traversal in forward direction:\n");
    while (node != NULL) {
        printf("%d ", node->val);
        last = node;
        node = node->right;
    }
    printf("\nTraversal in reverse direction:\n");
    while (last != NULL) {
        printf("%d ", last->val);
        last = last->left;
    }
}

// Global variable to store the previous visited node.
struct TreeNode* prev = NULL;

// Function to convert the given binary search tree to a doubly linked list.
void BSTToDoublyLinkedList(struct TreeNode* root, struct TreeNode** head) {
    if (root == NULL) return;

    // Recursively convert the left subtree.
    BSTToDoublyLinkedList(root->left, head);

    // Now convert this node.
    if (prev == NULL) {
        // If the previous node is NULL, it means this is the leftmost node.
        *head = root;
    } else {
        // Adjust the pointers.
        root->left = prev;
        prev->right = root;
    }
    // Mark this node as previous.
    prev = root;

    // Recursively convert the right subtree.
    BSTToDoublyLinkedList(root->right, head);
}

int main() {
    // Example to create a binary search tree.
    struct TreeNode* root = newTreeNode(10);
    root->left = newTreeNode(6);
    root->right = newTreeNode(14);
    root->left->left = newTreeNode(4);
    root->left->right = newTreeNode(8);
    root->right->left = newTreeNode(12);
    root->right->right = newTreeNode(16);

    // Head of the doubly linked list.
    struct TreeNode* head = NULL;

    // Convert the BST to doubly linked list.
    BSTToDoublyLinkedList(root, &head);

    // Print the doubly linked list.
    printList(head);

    return 0;
}
