**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int n = numsSize;
    int *ans = (int*)malloc(n*sizeof(int));
    ans[0] = nums[0];
    for(int i =1; i<n; i++){
        ans[i] = nums[i]+ans[i-1];
    }
    return ans;
}