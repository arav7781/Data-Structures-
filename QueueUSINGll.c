#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *front = 0;
struct node *rear = 0;
void enqueue(int x){
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = 0;
    if(front == 0 && rear == 0){
        printf("The queue is enmpty.");
    }
    else{
        rear->next = newnode;//rear wala hi move krra jaise jaise newnode add hore hai 
        rear = newnode;//front wala 0 pr hi rhega 
    }
}
void dequeue(){
    struct node *temp;
    front = temp;
    if(front == 0 && rear == 0){
        printf("The queue is enmpty.");
    }
    else{
        front = front->next;
        free(temp);
    }
}
void display(){
    struct node *temp;
    temp = front;
    if(front == 0){
        printf("There is no data in the list.");
    }
    else{
        while(temp!=rear){
            printf("%d",front->data);
            front = front->next;
        }
        printf("%d",front -> data);//last wale node ka data print krne ke liye.
    }
}

int main(){
    int choice, x;
    while(1){
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &x);
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}