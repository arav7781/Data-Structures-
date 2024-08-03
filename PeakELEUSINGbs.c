#include <stdio.h>

int findPeakElement(int arr[], int low, int high, int n) {
    int mid = low + (high - low) / 2;

    // Check if mid element is a peak
    if ((mid == 0 || arr[mid - 1] <= arr[mid]) &&
        (mid == n - 1 || arr[mid + 1] <= arr[mid])) {
        return mid;
    }
    // If the left neighbor is greater, move to the left half
    else if (mid > 0 && arr[mid - 1] > arr[mid]) {
        return findPeakElement(arr, low, mid - 1, n);
    }
    // If the right neighbor is greater, move to the right half
    else {
        return findPeakElement(arr, mid + 1, high, n);
    }
}

int main() {
    int arr[] = {1, 3, 20, 4, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int peakIndex = findPeakElement(arr, 0, n - 1, n);
    printf("Peak element is at index %d and its value is %d\n", peakIndex, arr[peakIndex]);
    return 0;
}
