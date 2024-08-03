#include<stdio.h>
void swap(int *a,int *b){
    int temp =*a;
    *a = *b;
    *b = temp;
}
void BubblesortRecursive(int arr[],int n){
    if(n==1) return;//Base case
    for(int i = 0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            swap(&arr[i],&arr[i+1]);
        }
    }
    BubblesortRecursive(arr,n-1);//Recursive call
}
int main(){
    int arr[5] = {1,253,2,23,3};
    int n = 5;
    BubblesortRecursive(arr,n);
    return 0;
    for(int i = 0;i<n;i++){
        printf("%d",arr[i]);
    }
}
