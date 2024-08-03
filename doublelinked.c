#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
    struct node* prev;
};
struct node *head = NULL;
void create(){
    struct node *newnode, *temp;
    int choice;
    printf("Whether you want to create a linked list (1 for yes & 0 for no): ");
    scanf("%d", &choice);
    
    while(choice){
        newnode = (struct node*)malloc(sizeof(struct node));//DMA for the newnode
        printf("Enter Data: ");
        // Read data into the new node
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        newnode->prev = NULL;
        
        if(head == NULL){
            // If the list is empty, initialize head
            head = temp = newnode;
        } 
        else{
            // Link the new node to the end of the list
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
        
        printf("Do you want to add another node (1 for yes & 0 for no): ");
        scanf("%d", &choice);
    }
}

// Function to display the doubly linked list
void display(){
    struct node* temp = head;//local pointer hai temp
    // Traverse the list and print each node's data kyuki aakhri node m null stored h addr mai
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main(){
    create();
    display();
    return 0;
}
