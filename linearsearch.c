#include <stdio.h>
int linearSearch(int *arr, int size, int target){
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; 
        }
    }
    return -1;
}

int main(){
    int arr[] = {3, 5, 7, 9, 11, 13, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    int result = linearSearch(arr, size, target);
    if (result != -1){
        printf("Element found%d\n", result);
    } 
    else{
        printf("Element not found.\n");
    }

    return 0;
}
