int comp(const void *x,const void *y){
    return (*(int*)x-*(int*)y);
}
bool containsDuplicate(int* nums, int numsSize) {
    qsort(nums,numsSize,sizeof(int),comp);
    for(int j=1;j<numsSize;j++){
        if(nums[j] == nums[j-1]){
            return 1;
        }
    }
    return 0;
}