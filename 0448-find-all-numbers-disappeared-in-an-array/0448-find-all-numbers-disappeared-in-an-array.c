/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsize, int* returnSize) {
    int *res=(int*)malloc(numsize*sizeof(int));
    int *count=(int*)calloc(numsize+1,sizeof(int));
    for(int i=0;i<numsize;i++){
        count[nums[i]]=1;
    }
    int k=0;
    for(int i=1;i<=numsize;i++){
        if(count[i]==0){
            res[k++]=i;
        }
    }
    *returnSize=k;
    return res;
}