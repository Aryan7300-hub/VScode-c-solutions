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
void mergeArray(int* arr1, int* arr2, int* n1, int n2){
    for(int i = 0; i<n2; i++){
        arr1[i + *n1] = arr2[i];
    }
    *n1 = *n1 + n2;
}
int main(){
    int arr1[100], arr2[100];
    int n, m;

    printf("Enter the size of Array1: ");
    scanf("%d", &n);
    createArray(arr1, n);

    printf("Enter the size of Array2: ");
    scanf("%d", &m);
    createArray(arr2, m);

    mergeArray(arr1, arr2, &n, m); //Merging array1 and array2 in array1
    printf("Merged Array: \n");
    printArray(arr1, n);

    return 0;
}