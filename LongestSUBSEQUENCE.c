#include <stdio.h>
#include <stdlib.h>
/*Double pointers (or pointers to pointers) are used in C to allow functions
 to modify the value of a pointer itself, 
rather than just the value it points to.
 This is particularly useful when you need a function to allocate memory
  for a pointer or change the pointer to point to a different memory location.*/
int lengthOfLIS(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    // Allocate memory for the dp array
    int* dp = (int*)malloc(numsSize * sizeof(int));
    
    // Initialize dp array with 1s
    for (int i = 0; i < numsSize; i++) {
        dp[i] = 1;
    }

    // Fill dp array
    for (int i = 1; i < numsSize; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = dp[i] > dp[j] + 1 ? dp[i] : dp[j] + 1;
            }
        }
    }

    // Find the maximum value in dp array
    int max = 0;
    for (int i = 0; i < numsSize; i++) {
        if (dp[i] > max) {
            max = dp[i];
        }
    }

    // Free the allocated memory
    free(dp);
    
    return max;
}

int main() {
    int nums[] = {10, 9, 2, 5, 3, 7, 101, 18};/*longest sorted subsequence*/
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    printf("Length of Longest Increasing Subsequence: %d\n", lengthOfLIS(nums, numsSize));
    return 0;
}
