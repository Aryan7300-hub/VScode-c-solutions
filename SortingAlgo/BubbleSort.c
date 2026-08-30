#include<stdio.h>
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
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubbleSort(int* arr, int n){
    for(int i = 0; i<n-1; i++){
        int isSwap = 0;
        for(int j = 0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j], &arr[j+1]);
                isSwap = 1;
            }
        }
        if(isSwap == 0) return;
    }
}
int main(){
    int arr[100];
    int n;

    printf("Enter the size of Array: ");
    scanf("%d", &n);

    createArray(arr, n);

    printf("Original Array: ");
    printArray(arr, n);

    bubbleSort(arr,n);

    printf("Sorted Array: ");
    printArray(arr,n);

    return 0;
}