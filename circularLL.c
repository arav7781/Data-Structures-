#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
    struct node* prev;
};
struct node *head = NULL,*tail;
void create(){
    struct node *newnode;
    int choice;
    printf("Whether you want to create a linked list (1 for yes & 0 for no): ");
    scanf("%d", &choice);
    
    while(choice){
        newnode = (struct node*)malloc(sizeof(struct node));//DMA for the newnode
        printf("Enter Data: ");
        // Read data into the new node
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        
        if(head == NULL){
            head = tail = newnode;
        } 
        else{
            tail->next = newnode;
            tail = newnode;
        }
        tail -> next = head;//to make it circular LL pehle wale ka addr last wale mai
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
        while (temp->next != head) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d ", temp->data); // To print the last node
    }
}

int main(){
    create();
    display();
}