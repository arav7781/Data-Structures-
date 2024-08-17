#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void rightView(struct Node* root) {
    if (root == NULL)
        return;

    struct Node* queue[100];//data type struct node hai kyuki queue ke andr nodes store krna h
    //ya pointer jo hai wo node pr point kr ske effectively.
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        int nodeCount = rear - front;
        for (int i = 1; i <= nodeCount; i++) {
            struct Node* currNode = queue[front++];//front++ se remove ho jayega current node
            //BFS traversal hai toh queue se nikal te jayenge ele after each expoloration
            if (i == nodeCount) {//agar i brabr h last node ke toh print right most node
                printf("%d ", currNode->data);
            }
            if (currNode->left != NULL) {
                queue[rear++] = currNode->left;//enqueue operation h left ka aur right ka one by one
            }
            if (currNode->right != NULL) {
                queue[rear++] = currNode->right;
            }
        }
    }
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);
    root->left->right->left = createNode(7);
    root->left->right->right = createNode(8);

    printf("Right view of the binary tree: ");
    rightView(root);
    return 0;
}
