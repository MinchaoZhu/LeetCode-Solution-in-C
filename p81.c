#include <stdio.h>
#include <stdbool.h>

/**
 * flag == 0: the subArray is rotated array;
 * flag == 1: the subArray is sequential array
 * */
bool findFunc(int* nums, int begin, int end, int target, bool flag){
    int mid = (begin+end)/2;
    if(target==nums[mid]||target==nums[begin]||target==nums[end]) return 1;
    if(end-begin==1||end==begin)return nums[begin]==target||nums[end]==target;
    if(flag){
        while(end>begin){
            mid = (begin+end)/2;
            if(nums[mid]>target){
                end = mid;
            }
            else if(nums[mid]<target){
                begin = mid+1;
            }
            else return 1;
        }
        return nums[begin]==target;
    }
    else{
        if(nums[mid]<nums[end]){
            if(target<nums[end]&&target>nums[mid]) return findFunc(nums,mid,end,target,1);
            else return findFunc(nums,begin,mid,target,0);
        }
        else if(nums[mid]>nums[end]){
            if(target>nums[begin]&&target<nums[mid]) return findFunc(nums,begin,mid,target,1);
            else return findFunc(nums,mid,end,target,0);
        }
        else{
            return findFunc(nums,mid,end,target,0)||findFunc(nums,begin,mid,target,0);
        }
    }
}

bool search(int* nums, int numsSize, int target) {
    if(!numsSize) return 0;
    return findFunc(nums,0,numsSize-1,target,0);
}




int main(void){
    int nums[5] = {1,3,1,1,1};
    int i;
    i = search(nums,5,0);
    printf("%d\n",i);


    return 0;
}