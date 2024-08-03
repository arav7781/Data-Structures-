#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to get the length of a linked list
int getLength(struct ListNode* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

// Function to get the intersection node
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB){
    int lenA = getLength(headA);
    int lenB = getLength(headB);
    
    // Align the start of both lists
    while (lenA > lenB) {
        headA = headA->next;
        lenA--;
    }
    
    while (lenB > lenA) {
        headB = headB->next;
        lenB--;
    }
    
    // Traverse both lists to find the intersection
    while (headA != NULL && headB != NULL) {
        if (headA == headB) {
            return headA;
        }
        headA = headA->next;
        headB = headB->next;
    }
    
    return NULL;
}

// Helper function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Test the function
int main() {
    // Create linked lists and test intersection
    struct ListNode* headA = createNode(1);
    headA->next = createNode(3);
    headA->next->next = createNode(5);
    
    struct ListNode* headB = createNode(2);
    headB->next = createNode(4);
    
    // Create intersection
    struct ListNode* intersect = createNode(7);
    intersect->next = createNode(9);
    
    headA->next->next->next = intersect;
    headB->next->next = intersect;
    
    struct ListNode* intersection = getIntersectionNode(headA, headB);
    if (intersection != NULL) {
        printf("Intersection at node with value: %d\n", intersection->val);
    } else {
        printf("No intersection.\n");
    }
    
    return 0;
}