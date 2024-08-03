#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

struct node *head = NULL, *tail = NULL;

void create() {
    struct node *newnode;
    int choice;
    printf("Whether you want to create a linked list (1 for yes & 0 for no): ");
    scanf("%d", &choice);

    while (choice) {
        newnode = (struct node*)malloc(sizeof(struct node)); // DMA for the newnode
        printf("Enter Data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) {
            head = tail = newnode;
            tail->next = head; // Make it circular
        } else {
            tail->next = newnode;
            tail = newnode;
            tail->next = head; // Keep it circular
        }

        printf("Do you want to add another node (1 for yes & 0 for no): ");
        scanf("%d", &choice);
    }
}

void display() {
    struct node *temp;
    if (head == NULL) {
        printf("The list is empty.");
    } else {
        temp = head;
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
    printf("\n");
}
void reverse() {
    if (tail == NULL) {
        printf("The List is empty.\n");
        return;
    }

    struct node *current, *nextnode, *prev;
    current = head; // Start from the head of the list
    prev = tail;    // Initialize prev to tail to handle circular nature

    while (current != tail) {
        nextnode = current->next; // Store the next node
        current->next = prev;     // Reverse the link
        prev = current;           // Move prev to current
        current = nextnode;       // Move to the next node
    }

    // Final reversal for the last node
    nextnode = current->next;
    current->next = prev;

    // Adjust the head and tail pointers
    head = current;
    tail = nextnode;
    tail->next = head; // Maintain the circular link
}

int main(){
    create();
    display();
    reverse();
    display();
}