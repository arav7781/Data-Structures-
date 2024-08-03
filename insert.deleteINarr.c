#include <stdio.h>
#include <stdlib.h>

int n = 4; // Initial size of the array

void insertion(int *arr, int n){
    int pos;
    printf("Enter the position: ");
    scanf("%d", &pos);

    if (pos < 0 || pos > n){
        printf("Invalid position!\n");
        return;
    }

    for (int i = n; i > pos; i--){
        arr[i] = arr[i - 1]; 
    }
    arr[pos] = 7; 
    n++; 

    printf("Array after insertion:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void deletion(int *arr, int n) {
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }

    int pos;
    printf("Enter the position: ");
    scanf("%d", &pos);

    if (pos < 0 || pos >= n) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1]; 
    }
    n--; 

    printf("Array after deletion:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void traversal(int *arr, int n) {
    printf("Array elements are: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void display(int *arr, int idx, int n) {
    if (idx == n){
        return;
    } 
    else{
        printf("%d ", arr[idx]);
        display(arr, idx + 1, n);
    }
}

int main() {
    int arr[100] = {1, 2, 3, 4};
    int ch;
    int idx = 0;

    do{
        printf("Enter the choice: 1:insertion 2:deletion 3:display 4:traversal 0:exit: ");
        scanf("%d", &ch);

        switch(ch){
            case 1:
                insertion(arr, n);
                break;
            case 2:
                deletion(arr, n);
                break;
            case 3:
                display(arr, idx, n);
                printf("\n");
                break;
            case 4:
                traversal(arr, n);
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("The entered choice is invalid.\n");
        }
    }while (ch != 0);

    return 0;
}
