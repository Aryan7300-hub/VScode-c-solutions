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
void insertionSort(int* arr, int n){
    for(int i = 1; i<n; i++){
        int j = i;
        while(j>=0 && arr[j-1] > arr[j]){
            swap(&arr[j-1], &arr[j]);
            j--;
        }
    }
    printf("jk");
}
int main(){
    int arr[100];
    int n;

    printf("Enter the size of Array: ");
    scanf("%d", &n);

    createArray(arr, n);

    printf("Original Array: ");
    printArray(arr, n);

    insertionSort(arr,n);

    printf("Sorted Array: ");
    printArray(arr,n);

    return 0;
}