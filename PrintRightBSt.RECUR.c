#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode *left, *right;
};

struct TreeNode* createNode(int data) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void rightViewUtil(struct TreeNode* root, int level, int* maxLevel) {
    if (root == NULL)
        return;

    if (*maxLevel < level) {
        printf("%d ", root->data);
        *maxLevel = level;
    }

    rightViewUtil(root->right, level + 1, maxLevel);
    rightViewUtil(root->left, level + 1, maxLevel);//vhi h agr right null h toh left will be the right view
}

void rightView(struct TreeNode* root) {
    int maxLevel = 0;
    rightViewUtil(root, 1, &maxLevel);
}

int main() {
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);
    root->left->right->left = createNode(7);

    printf("Right view of the binary tree: ");
    rightView(root);

    return 0;
}
