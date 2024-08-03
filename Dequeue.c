#include <stdio.h>
#include <stdlib.h>

#define N 5

int dequeue[N];
int front = -1;
int rear = -1;

void enqueuefront(int x) {
    if ((front == 0 && rear == N - 1) || (front == rear + 1)) {
        printf("Queue is full\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        dequeue[front] = x;
    } else if (front == 0) {
        front = N - 1;
        dequeue[front] = x;
    } else {
        front--;
        dequeue[front] = x;
    }
}

void enqueuerear(int x) {
    if ((front == 0 && rear == N - 1) || (front == rear + 1)) {
        printf("Queue is full\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        dequeue[rear] = x;
    } else if (rear == N - 1) {
        rear = 0;
        dequeue[rear] = x;
    } else {
        rear++;
        dequeue[rear] = x;
    }
}

void dequeuefront() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    } else if (front == rear) {
        printf("Dequeued element: %d\n", dequeue[front]);
        front = rear = -1;
    } else if (front == N - 1) {
        printf("Dequeued element: %d\n", dequeue[front]);
        front = 0;
    } else {
        printf("Dequeued element: %d\n", dequeue[front]);
        front++;
    }
}

void dequeuerear() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    } else if (front == rear) {
        printf("Dequeued element: %d\n", dequeue[rear]);
        front = rear = -1;
    } else if (rear == 0) {
        printf("Dequeued element: %d\n", dequeue[rear]);
        rear = N - 1;
    } else {
        printf("Dequeued element: %d\n", dequeue[rear]);
        rear--;
    }
}

void display() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are: ");
        int i = front;
        while (1) {
            printf("%d ", dequeue[i]);
            if (i == rear) {
                break;
            }
            i = (i + 1) % N;
        }
        printf("\n");
    }
}

int main() {
    int choice, value;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue at Front\n");
        printf("2. Enqueue at Rear\n");
        printf("3. Dequeue from Front\n");
        printf("4. Dequeue from Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue at front: ");
                scanf("%d", &value);
                enqueuefront(value);
                break;
            case 2:
                printf("Enter value to enqueue at rear: ");
                scanf("%d", &value);
                enqueuerear(value);
                break;
            case 3:
                dequeuefront();
                break;
            case 4:
                dequeuerear();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
