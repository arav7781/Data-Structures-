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

void printRightView(struct TreeNode* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    if (root->right) {
        printRightView(root->right);
    } else if (root->left) {//else if isliye hai agr right hua hi nahi toh left wale hi right
    //consider honge
        printRightView(root->left);
    }
}

int main() {
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->left->right->left = createNode(6);
    root->right->right = createNode(7);
    
    printf("Right view of the tree: ");
    printRightView(root);

    return 0;
}
