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

void DeletefromBeg() {
    struct node* temp;
    temp = head;
    if (head == NULL) {
        printf("There is no element in the list.");
    } else if (head->next == head) { // Only one node
        free(head);
        head = tail = NULL;
    } else {
        tail->next = head->next;
        head = head->next;
        free(temp);
    }
}

void DeleteFromEnd() {
    struct node *current, *prevnode;
    if (head == NULL) {
        printf("There is no element in the list.");
    } else if (head->next == head) { // Only one node
        free(head);
        head = tail = NULL;
    } else {
        current = head;
        while (current->next != head) {
            prevnode = current;
            current = current->next;
        }
        prevnode->next = head;
        tail = prevnode;
        free(current);
    }
}

void DeleteFromPOS() {
    struct node *temp, *nextnode;
    int pos, i = 1;
    printf("Enter the position from where you want to delete the data from: ");
    scanf("%d", &pos);

    if (pos == 1) {
        DeletefromBeg();
        return;
    }

    temp = head;
    while (i < pos - 1 && temp->next != head) {
        temp = temp->next;
        i++;
    }

    if (temp->next == head) {
        printf("Position out of range.\n");
    } else {
        nextnode = temp->next;
        temp->next = nextnode->next;
        if (nextnode == tail) {
            tail = temp;
        }
        free(nextnode);
    }
}

int main() {
    int ch;
    do {
        printf("Enter the choice 1: create 2: display 3: Delete from Beginning 4: Delete from End 5: Delete from Position 0: exit: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                DeletefromBeg();
                break;
            case 4:
                DeleteFromEnd();
                break;
            case 5:
                DeleteFromPOS();
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("The entered choice is invalid.\n");
        }
    } while (ch != 0);
    return 0;
}
