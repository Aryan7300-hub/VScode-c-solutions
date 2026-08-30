#include<stdio.h>
#include<stdlib.h>
void createArray(int* arr, int n){

    printf("Enter the values in array: \n");
    for(int i = 0; i<n; i++){
        printf("Enter value of index %d: ", i);
        scanf("%d", &arr[i]);
    }
    printf("\n");
}
void printArray(int arr[], int n){

    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void merge(int* arr, int left, int mid, int right){
    int* temp = (int*)malloc((right-left+1)*sizeof(int));

    int i = left;
    int j = mid+1;
    int k = 0;

    while(i<=mid && j<=right){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }else{
            temp[k++] = arr[j++];
        }
    }
    while(i<=mid) temp[k++] = arr[i++];
    while(j<=right) temp[k++] = arr[j++];

    for(i = left; i<=right; i++){
        arr[i] = temp[i-left];
    }
    free(temp);

}
void mergeSort(int* arr, int left, int right){
    if(left>=right) return;

    int mid = left + (right-left)/2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);

    merge(arr, left, mid, right);
}
int main(){
    int arr[100];
    int n;

    printf("Enter the size of Array: ");
    scanf("%d", &n);

    createArray(arr, n);

    printf("Original Array: ");
    printArray(arr, n);

    mergeSort(arr, 0, n-1);

    printf("Sorted Array: ");
    printArray(arr, n);

    return 0;
}
//g++ MergeSort.c -o MergeSort.exe
//./MergeSort.exe