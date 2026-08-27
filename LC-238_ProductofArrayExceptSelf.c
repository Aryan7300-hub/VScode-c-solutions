/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* result = malloc(numsSize* sizeof(int));

    for(int i = 0; i<numsSize; i++){
        result[i] = 1;
    }

    for(int i = 1; i < numsSize; i++){
        result[i] = nums[i-1] * result[i-1];
    }

    int right = 1;
    for(int j = numsSize-1; j >= 0; j--){
        result[j] *= right;
        right *= nums[j]; 
    }
    *returnSize = numsSize;

    return result;
}