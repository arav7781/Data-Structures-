#include <stdio.h>
#include <stdlib.h>

#define BUCKETS 10
#define INTERVAL 10

typedef struct Bucket {
    int count;
    int* values;
} Bucket;

void bucketSort(int arr[], int n);
void insertionSort(int arr[], int n);
void printArray(int arr[], int n);

int main() {
    int arr[] = {78, 17, 39, 26, 72, 94, 21, 12, 23, 68};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: \n");
    printArray(arr, n);
    
    bucketSort(arr, n);
    
    printf("Sorted array: \n");
    printArray(arr, n);
    
    return 0;
}

void bucketSort(int arr[], int n) {
    // Create buckets
    Bucket buckets[BUCKETS];
    for (int i = 0; i < BUCKETS; i++) {
        buckets[i].count = 0;
        buckets[i].values = (int*)malloc(sizeof(int) * n);
    }
    
    // Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int index = arr[i] / INTERVAL;
        buckets[index].values[buckets[index].count++] = arr[i];
    }
    
    // Sort each bucket and concatenate
    int k = 0;
    for (int i = 0; i < BUCKETS; i++) {
        if (buckets[i].count > 0) {
            insertionSort(buckets[i].values, buckets[i].count);
            for (int j = 0; j < buckets[i].count; j++) {
                arr[k++] = buckets[i].values[j];
            }
        }
    }
    
    // Free memory
    for (int i = 0; i < BUCKETS; i++) {
        free(buckets[i].values);
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
