#include<stdio.h>
#include<stdlib.h>
void createArray(int arr[100][100], int m, int n){

    printf("Enter the values in array \n");
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            printf("Enter value of index %d %d: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    printf("\n");
}
void printArray(int arr[100][100], int m, int n){
    printf("\nDisplaying Values of array: \n");

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("Value of %d %d: %d\n", i, j, arr[i][j]);
        }    
    }
    printf("\n");
}
void AddMatrix(int arr1[100][100], int arr2[100][100], int m1, int n1, int m2, int n2){
    if(m1 != m2 || n1 != n2) return;

    for(int i = 0; i<m1; i++){
        for(int j = 0; j<n1; j++){
            arr1[i][j] += arr2[i][j];
        }
    }
}
int main(){
    int arr1[100][100], arr2[100][100];
    int m1, n1, m2, n2;

    printf("Enter the rows and cols of Frist matrix: ");
    scanf("%d%d", &m1, &n1);

    createArray(arr1, m1, n1);
    printArray(arr1, m1, n1);

    printf("Enter the rows and cols of Second matrix: ");
    scanf("%d%d", &m2, &n2);

    createArray(arr2, m2, n2);
    printArray(arr2, m2, n2);

    AddMatrix(arr1, arr2, m1, n1, m2, n2);
    printf("Added Matrix: \n");
    printArray(arr1, m1, n1);

    return 0;
}