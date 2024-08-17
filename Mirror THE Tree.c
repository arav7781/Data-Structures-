#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode* createNode(int data) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
// Function to swap the left and right children of each node to create a mirror image.
void mirrorTree(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    struct TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirrorTree(root->left);
    mirrorTree(root->right);
}
void inOrder(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

int main(){
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Original tree (In-order): ");
    inOrder(root);
    printf("\n");
    mirrorTree(root);

    printf("Mirror image tree (In-order): ");
    inOrder(root);
    printf("\n");

    return 0;
}
