#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target) {
    if(!numsSize){
        return 0;
    }
    if(nums[numsSize-1]<target){
        return numsSize;
    }
    numsSize-=2;
    while(numsSize>=0){
        if(nums[numsSize+1]>=target&&nums[numsSize]<target)
            return numsSize+1;
        --numsSize;
    }
    return 0;
}



int main(void){
    int A[1] = {1};
    int ret;
    ret = searchInsert(A,1,1);
    printf("%d\n",ret);
    return 0;
}