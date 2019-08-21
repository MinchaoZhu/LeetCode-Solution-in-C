#include <stdio.h>

int recur(int* nums, int begin, int end){
    int mid = (begin+end)/2;
    if(end-begin>1){ 
        if(nums[mid]>nums[end]) return recur(nums, mid, end);
        else return recur(nums,begin,mid);
    }
    else return nums[begin]<nums[end]?nums[begin]:nums[end];
}

int findMin(int* nums, int numsSize){
    return recur(nums,0,numsSize-1);
}

int main(void){
    int nums[5] = {3,4,5,1,2};
    int res;
    res = findMin(nums,5);
    printf("%d\n",res);
}