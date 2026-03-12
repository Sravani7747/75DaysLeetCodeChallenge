/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int n, int target, int* returnSize) {
    int *b=(int*)malloc(2*sizeof(int*));
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(nums[i]+nums[j]==target){
                b[0]=i;
                b[1]=j;
                *returnSize=2;
                return b;
            }
        }
    }
    return 0;
    
}