#include <stdio.h>

int firstMissingPositive(int* nums, int numsSize) {
    int i,temp;
    for(i = 0;i<numsSize;++i){
        while(nums[i]>0&&nums[i]<numsSize+1&&nums[nums[i] - 1] != nums[i]){
            temp = nums[i];
            nums[i] = nums[nums[i]-1];
            nums[temp-1] = temp;
        }
    }
    for(i = 0;i<numsSize;++i){
        if(nums[i]!=i+1)
            return i+1;
    }
    return numsSize+1;
    
}

int main(void){
    int a[4] = {3,4,-1,1};
    int i = firstMissingPositive(a,4);
    printf("%d\n",i);
    return 0;    
}