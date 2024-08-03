#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int x){
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

void pop() {
    struct node *temp;
    if (top == NULL) {
        printf("The stack is empty.\n");
    } else {
        temp = top;
        printf("Popped element: %d\n", top->data);
        top = top->next;
        free(temp);
    }
}

void peek() {
    if (top == NULL) {
        printf("The stack is empty.\n");
    } else {
        printf("Top element is: %d\n", top->data);
    }
}

void display() {
    struct node *temp = top;
    if (top == NULL) {
        printf("There is no item in the stack.\n");
    } else {
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int ch, x;
    do {
        printf("Enter the choice 1:push 2:pop 3:peek 4:display 0:exit: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &x);
                push(x);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
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
