#include <stdio.h>



void reverseNums(int * nums, int start, int end){
    int temp;
    while(start<=end){
        temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        ++start;
        --end;
    }
}


void nextPermutation(int* nums, int numsSize) {
    int i = numsSize-1, j = numsSize - 2,temp = 0;    
    if(numsSize<=1)
        return;
    for(;j>=0;--i,--j){
        if(nums[j]<nums[i]){
            break;
        }
    }
    reverseNums(nums,i,numsSize-1);
    if(j<0)
        return;
    for(;i<numsSize;++i){
        if(nums[j]<nums[i]){
            temp = nums[j];
            nums[j] = nums[i];
            nums[i] = temp;
            return;
        }

    }
}


int main(void){
    int a[6] = {5,4,7,5,3,2},i;
    nextPermutation(a,6);

    for(i = 0;i<6;++i){
        printf("%d ",a[i]);
    }
    printf("\n");

    return 0;
}