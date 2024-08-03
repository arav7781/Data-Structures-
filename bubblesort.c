#include<stdio.h>
#include<stdbool.h>
int main(){
    int arr[5] = {5,4,3,2,1};
    int n = 5;
    printf("unsorted array:\n");
    for(int i = 0;i<5;i++){
        printf("%d ",arr[i]);
    }
    for(int i = 0;i<n-1;i++){//no of passes ke liye hai.
        bool flag = true;//array abhi sort nhi hua h false ka matlab
        for(int j = 0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];  
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = false;//bubble sort optimization(time complexity)
            }
            
        }
        if(flag == true) break;
    }
    printf("\n");
    printf("sorted array:\n");
    for(int i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}