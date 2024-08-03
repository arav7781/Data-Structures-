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
/*Deletion of the code
(i)Delete from the begginning
(ii) Delete from the end
(iii) Delete from the position*/
void DeleteFromtheBegin(){
    if(head == NULL){
        printf("There is no node in the list.");
    }
    else{
        struct node *temp;//temp is used to traverse through the list
        temp = head;//head hogya 100
        head = head->next;//head ab hogya 200
        free(temp);//100 wale pe jo data hai wo free ho
    }
}
void DeleteFromtheEnd(){
    struct node *temp,*prevnode;
    temp = head;
    while(temp->next != 0){
        prevnode = temp;
        temp = temp->next;
    }
    if(head == temp){
        head = 0;
    }
    else{
        prevnode->next = 0;
        free(temp);
    }
}
void DeleteFromAnyPosition(){
    struct node *temp,*nextnode;
    int pos,i = 1;
    printf("Enter the position from where you want to delete the data from:");
    scanf("%d",&pos);
    temp = head;
    while(i<pos-1){
        temp = temp->next;
        i++;
    }
    nextnode = temp->next;
    temp->next = nextnode->next;
    free(nextnode);
}
void display(){
    struct node* temp = head;//local pointer hai temp
    // Traverse the list and print each node's data kyuki aakhri node m null stored h addr mai
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
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
    DeleteFromtheBegin();
    printf("The Linked List after the Deletion of the first element is:");
    display();
    DeleteFromtheEnd();
    printf("The Linked List after the Deletion of the Last element is:");
    display();
    DeleteFromAnyPosition();
    printf("The Linked List after the Deletion of your selected position is:");
    display();
    return 0;
}
