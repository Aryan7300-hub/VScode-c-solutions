#include<stdlib.h>
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int compare(const void* a, const void* b){
    int* x = *(int**)a;
    int* y = *(int**)b;
    return x[0]-y[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    if(intervalsSize == 0){
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    
    qsort(intervals, intervalsSize, sizeof(int*), compare);

    int** result = (int**)malloc(intervalsSize * sizeof(int*));
    for(int i = 0; i<intervalsSize; i++){
        result[i] = (int*)malloc(2*sizeof(int));
    }

    result[0][0] = intervals[0][0];
    result[0][1] = intervals[0][1];
    int count = 1;

    for(int i = 0; i<intervalsSize; i++){
        if(result[count-1][1] >= intervals[i][0]){
            if(result[count-1][1] < intervals[i][1]){
                result[count-1][1] = intervals[i][1];
            }
        }else{
            result[count][0] = intervals[i][0];
            result[count][1] = intervals[i][1];
            count++;
        }
    }

    *returnSize = count;
    *returnColumnSizes = (int*)malloc(count*sizeof(int));
    for(int i = 0; i<count; i++){
        (*returnColumnSizes)[i] = 2;
    }

    return result;
}