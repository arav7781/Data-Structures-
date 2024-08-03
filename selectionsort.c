#include <stdio.h>

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Selection sort function
void selectionSort(int arr[], int n) {
    int i, j, min_index;
    
    // Traverse the array
    for (i = 0; i < n - 1; i++) {
        // Find the minimum element in unsorted array
        min_index = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index])
                min_index = j;
        }
        
        // Swap the found minimum element with the first element
        swap(&arr[min_index], &arr[i]);
    }
}

int main() {
    int n;
    
    // Input size of array
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    
    // Input array elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    // Perform selection sort
    selectionSort(arr, n);
    
    // Print sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    return 0;
}
