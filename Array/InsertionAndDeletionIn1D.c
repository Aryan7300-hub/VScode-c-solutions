#include<stdio.h>
#include<stdlib.h>
void createArray(int *arr, int n){

    printf("Enter the values: \n");
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
}
void Insertion(int *arr, int *n, int idx, int val){
    if(idx > *n || idx<0) return;

    for(int i = *n; i>idx; i--){
        arr[i] = arr[i-1];
    }
    arr[idx] = val;
    (*n)++;

}
void deleteElement(int *arr, int *n, int idx){
    if(idx>*n || idx<0) return;

    for(int i = idx; i<*n-1; i++){
        arr[i] = arr[i+1];
    }
    (*n)--;
}
int main(){
    int arr[100];
    int n;
    int i, val, idx;

    printf("Enter the size of Array: ");
    scanf("%d", &n);

    createArray(arr, n);
    printArray(arr, n);

    printf("Enter the index and value for Insertion: ");
    scanf("%d%d", &i, &val);
    Insertion(arr, &n, i, val);

    printArray(arr, n);

    printf("Enter the index for delete: ");
    scanf("%d", &idx);
    deleteElement(arr, &n, idx);

    printArray(arr, n);

    return 0;
}