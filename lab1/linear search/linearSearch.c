int missingNumber(int* nums, int numsSize) {
    int c;
    c=numsSize;
    int sum=(c*(c+1))/2;
    int missing=sum;
    for(int i=0;i<numsSize;i++) {
        missing=missing-nums[i];
    }
    return missing;
}
