#include <stdio.h>
#include <stdlib.h>

#define N 5

int stack[N];
int top = -1;

void push() {
    int x;
    printf("Enter Data: ");
    scanf("%d", &x);
    if (top == N - 1) {
        printf("The stack is overflow.\n");
    } else {
        top++;
        stack[top] = x;
    }
}

void pop() {
    int item;
    if (top == -1) {
        printf("The stack is underflow.\n");
    } else {
        item = stack[top];
        top--;
        printf("The removed data is %d\n", item);
    }
}

void peek() {
    if (top == -1) {
        printf("The stack is underflow.\n");
    } else {
        printf("The top most element of the stack is: %d\n", stack[top]);
    }
}

void display() {
    if (top == -1) {
        printf("The stack is empty.\n");
    } else {
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int ch;
    do {
        printf("Enter the choice 1:push 2:pop 3:peek 4:display 0:exit: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                push();
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
