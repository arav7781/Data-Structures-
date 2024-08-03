#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct node {
    int data;
    struct node *next;
};

// Head of the linked list
struct node *head = NULL;

// Function to calculate and print the length of the linked list
void lengthOfLinkedList() {
    int count = 0;
    struct node *temp = head; // Use a local temp pointer

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("The length of the linked list is: %d\n", count);
}

int main() {
    struct node *newnode, *temp;
    head = NULL; // Initialize head to NULL

    int choice;
    printf("Do you want to make a linked list? If yes, press 1 and if no, press 0: ");
    scanf("%d", &choice);

    while (choice) {
        // Dynamically allocate memory for the new node
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->next = NULL; // Initialize the next pointer to NULL

        printf("Enter data: ");
        scanf("%d", &newnode->data);

        if (head == NULL) {
            head = temp = newnode; // Initialize head and temp to newnode
        } else {
            temp->next = newnode; // Link the new node to the end of the list
            temp = newnode;       // Move the temp pointer to the new node
        }

        printf("Do you want to continue adding more nodes? (1 for yes, 0 for no): ");
        scanf("%d", &choice);
    }

    // Print the linked list
    temp = head;
    printf("The linked list is: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    // Print the length of the linked list
    lengthOfLinkedList();

    return 0;
}
