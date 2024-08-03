#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
    struct node* prev;
};
struct node *head = NULL,*tail;
void create(){
    struct node *newnode, *temp = 0;
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
            head = tail = newnode;
        } 
        else{
            // Link the new node to the end of the list
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
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
void insertATBeg(){
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter Data which you want to insert at the beggining:");
    scanf("%d",&newnode->data);
    if(head == 0){
        head = newnode;
    }
    else{
        head->prev = newnode;
        newnode->next = head;
        head = newnode;
    }
}
    
void insertatTHEEND(){
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter Data which you want to insert at the End:");
    scanf("%d",&newnode->data);
    if(head == 0){
        head = newnode;
    }
    else{
        tail->next = newnode;
        newnode->prev = tail;
        newnode->next = 0;
        tail = newnode;
    }
}
void insertatPOS(int pos){
     struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter Data which you want to insert at the %dth pos:",pos);
    scanf("%d",&newnode->data);
    if(head == 0){
        head = newnode;
    }
    else{
        int i = 1;
        if(pos<1){
            printf("INVALID POSITION");
        }
        else if(pos == 1){
            insertATBeg();
        }
        else{
            struct node *temp;
            temp = head;
            while(i<pos-1){
                temp = temp->next;
                i++;
            }
            newnode->prev = temp;
            newnode->next = temp->next;
            temp->next = newnode;
            newnode->next->prev = newnode;//newnode ke next node ke prev mai newnode ka addr store.
            
        }
    }
}
int main(){
    int pos;
    
    create();
    display();
    insertATBeg();
    printf("Linked List after Insertion at the Beginning is:");
    display();
    insertatTHEEND();
    printf("Linked List after Insertion at the END is:");
    display();
  
    printf("Enter the position:");
    scanf("%d",&pos);
    insertatPOS(pos);
    printf("Linked List after Insertion at the %dth position is:",pos);
    display();
    return 0;
}
