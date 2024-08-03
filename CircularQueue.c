#include<stdio.h>
#define N 5
int queue[N];
int front = -1;
int rear = -1;
void enqueue(){
    int x;
    printf("Enter the data:");
    scanf("%d",&x);
    if(rear == -1 && front == -1){
        front = rear = 0;
        queue[rear] = x;
    }
    else if((rear + 1)%N == front){
        printf("Queue is full.");
    }
    else{
        rear = (rear + 1)%N;//rear 4 h aur N h 5 toh rear 0 pe point krega ab
        queue[rear] = x;//empty spaces jo thi aage arr m ab uspe bhi data aajayega.
        //circular arr concept
    }
}
void dequeue(){
    if(rear == -1 && front == -1){
        printf("Queue is empty.");//something WRONG
    }
    else if(front == rear){
        front = rear = -1;
    }
    else{
        front = (front + 1)%N;//front ek index aage shift ho jayega 
        //i++ ka kaam krra hai
    }
}
void display(){
    if(front == -1 && rear == -1){
        printf("The Queue is Empty.");
    }
    else{
        int i = 0;
        printf("Queue is:\n");
        while(i!=rear){
            printf("%d",queue[i]);
            i = (i+1)%N;
        }
        printf("%d",queue[rear]);
    }
}
int main(){
    int ch;
    do {
        printf("Enter the choice 1:enqueue 2:dequeue 3:display 0:exit: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
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