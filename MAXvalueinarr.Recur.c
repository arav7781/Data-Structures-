#include <stdio.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))  // Macro to find the maximum

int max(int *arr, int idx, int n) {
    if (idx == n - 1) {
        return arr[idx];  // base case
    } else {
        return MAX(arr[idx], max(arr, idx + 1, n));  // recursive call
    }
}

int main() {
    int idx = 0;
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int maxValue = max(arr, idx, n);
    printf("The max value present in the array is: %d\n", maxValue);
    return 0;
}
