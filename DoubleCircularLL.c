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

        if(head == NULL) {
            head = tail = newnode;
            tail->next = head; 
            tail -> prev = head;
        } 
        else{
            tail -> next = newnode;
            newnode -> prev = tail;
            newnode -> next = head;
            head -> prev = newnode;//circular bnane ke liye
            tail = newnode;
        }

        printf("Do you want to add another node (1 for yes & 0 for no): ");
        scanf("%d", &choice);
    }
}
void display(){
    struct node *temp;
    temp = head;
    if(head == 0){
        printf("There is no data in the list.");
    }
    else{
        while(temp!=tail){
            printf("%d",temp->data);
            temp = temp->next;
        }
        printf("%d",temp -> data);//last wale node ka data print krne ke liye.
    }
}
int main(){
    create();
    display();
}