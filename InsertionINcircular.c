#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;  // Note: prev is not used in this code but included in struct definition
};

struct node *head = NULL, *tail = NULL;

void create() {
    struct node *newnode;
    int choice;
    printf("Do you want to create a linked list (1 for yes & 0 for no): ");
    scanf("%d", &choice);

    while (choice) {
        newnode = (struct node*)malloc(sizeof(struct node)); // DMA for the newnode
        printf("Enter Data: ");
        scanf("%d", &newnode->data);
        newnode->next = newnode->prev = NULL;

        if (head == NULL) {
            head = tail = newnode;
            tail->next = head;
        } else {
            tail->next = newnode;
            tail = newnode;
            tail->next = head;
        }

        printf("Do you want to add another node (1 for yes & 0 for no): ");
        scanf("%d", &choice);
    }
}

void display() {
    struct node *temp;
    if (head == NULL) {
        printf("The list is empty.\n");
    } else {
        temp = head;
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    }
}

void InsertionAtBeg() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = newnode->prev = NULL;

    if (head == NULL) {
        head = tail = newnode;
        tail->next = head;
    } else {
        newnode->next = head;
        tail->next = newnode;
        head = newnode;
    }
}

void InsertAtEnd() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = newnode->prev = NULL;

    if (head == NULL) {
        head = tail = newnode;
        tail->next = head;
    } else {
        tail->next = newnode;
        newnode->next = head;
        tail = newnode;
    }
}

void InsertAtPos() {
    struct node *newnode, *temp;
    int pos, i = 1;

    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = newnode->prev = NULL;

    printf("Enter the position: ");
    scanf("%d", &pos);

    if (pos == 1) {
        InsertionAtBeg();
    } else {
        temp = head;
        while (i < pos - 1 && temp->next != head) {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
        if (newnode->next == head) {
            tail = newnode;
        }
    }
}

void checkIfCircularLL() {
    if (tail != NULL && tail->next == head) {
        printf("The linked list is circular.\n");
    } else {
        printf("The linked list is not circular.\n");
    }
}

int main() {
    create();
    display();

    InsertionAtBeg();
    display();

    InsertAtPos();
    display();

    InsertAtEnd();
    display();

    checkIfCircularLL();

    return 0;
}
