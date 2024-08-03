#include <stdio.h>
/*optimized binary search 
as it takes less no of steps*/
int binarySearch(int *arr, int left, int right, int x){
    while(left <= right) {
        int mid = left + ((x - arr[left]) * (right - left) / (arr[right] - arr[left]));
        if(arr[mid] == x)
            return mid;
        if(arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}
/*It works by estimating the position of the target value, 
using a formula that interpolates between the low and
 high indices based on the value being searched for.*/
int main(){
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = binarySearch(arr, 0, n - 1, x);
    if(result == -1)
        printf("Element is not present in array\n");
    else
        printf("Element is present in the array\n");
}
