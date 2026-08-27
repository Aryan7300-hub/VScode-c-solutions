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
            printf("%d ", arr[i][j]);
        }    
        printf("\n");
    }
    printf("\n");
}
int multiplyMatrix(int arr1[100][100], int arr2[100][100],int result[100][100], int m1, int n1, int m2, int n2){
    if(n1 != m2) return 0;

    for(int i = 0; i < m1; i++)
    {
        for(int j = 0; j < n2; j++)
        {
            result[i][j] = 0;

            for(int k = 0; k < n1; k++)
            {
                result[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    return 1;
}
int main(){
    int arr1[100][100], arr2[100][100], result[100][100];
    int m1, n1, m2, n2;

    printf("Enter the rows and cols of Matrix: ");
    scanf("%d%d", &m1, &n1);

    createArray(arr1, m1, n1);
    printArray(arr1, m1, n1);


    printf("Enter the rows and cols of Matrix: ");
    scanf("%d%d", &m2, &n2);

    createArray(arr2, m2, n2);
    printArray(arr2, m2, n2);


    
    if(multiplyMatrix(arr1,arr2, result, m1, n1, m2, n2)){
        printf("\nMultiplication Matrix:\n");
        printArray(result, m1, n2);
    }else{
        printf("\nMatrix multiplication is not possible.\n");
    }

    return 0;
}