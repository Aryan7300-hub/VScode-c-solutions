#include<stdio.h>
#include<stdlib.h>
void createArray(int* arr, int n){

    printf("Enter the values in array \n");
    for(int i = 0; i<n; i++){
        printf("Enter value of index %d: ", i);
        scanf("%d", &arr[i]);
    }
    printf("\n");
}
void printArray(int arr[], int n){
    printf("\nDisplaying Values of array: \n");

    for(int i = 0; i < n; i++){
        printf("Value of index %d: %d\n", i, arr[i]);
    }
    printf("\n");
}
void sortArray(int* arr, int n){
    for(int i = 1; i<n; i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
int BinarySearch(int* arr, int n, int val){
    int left = 0;
    int right = n-1;
    while(left<=right){
        int mid = left + (right-left)/2;
        if(arr[mid] == val){
            return mid;
        }else if(arr[mid] < val){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return -1;
}
int main(){
    int arr[100];
    int n;
    int val;

    printf("Enter the size of Array: ");
    scanf("%d", &n);

    createArray(arr, n);
    printArray(arr, n);

    printf("Enter the value to Search in array: ");
    scanf("%d", &val);


    sortArray(arr, n);
    printf("Sorted array");
    printArray(arr, n);

    int idx = BinarySearch(arr, n, val);
    printf("Index of value in array: %d\n", idx);

    return 0;
}