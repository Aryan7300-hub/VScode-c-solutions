#include<stdio.h>
#include<stdlib.h>
void createArray(int* arr, int n){

    printf("Enter the values in array \n");
    for(int i = 0; i<n; i++){
        printf("Enter value of index %d: ", i);
        scanf("%d", &arr[i]);
    }
}
void printArray(int arr[], int n){
    printf("\nDisplaying Values of array: \n");

    for(int i = 0; i < n; i++){
        printf("Value of index %d: %d\n", i, arr[i]);
    }
    prinf("\n");
}
int Search(int* arr, int n, int val){
    for(int i = 0; i<n; i++){
        if(arr[i] == val) return i;
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
    
    int idx = Search(arr, n, val);
    printf("Index of value in array: %d\n", idx);

    return 0;
}