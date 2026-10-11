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
void Transpose(int arr[100][100], int m, int n){
   if(m != n) return;

   for(int i = 0; i < m; i++){
    for(int j = i+1; j < n; j++){
        int temp = arr[i][j];
        arr[i][j] = arr[j][i];
        arr[j][i] = temp;
    }
   }
}
int main(){
    int arr[100][100];
    int m, n;

    printf("Enter the rows and cols of Matrix: ");
    scanf("%d%d", &m, &n);

    createArray(arr, m, n);
    printArray(arr, m, n);

    
    Transpose(arr, m, n);
    printf("Transposed matrix ");
    printArray(arr, m, n);

    return 0;
}