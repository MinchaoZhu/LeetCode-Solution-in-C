#include <stdio.h>
#include <stdlib.h>
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int first = 0,end = numsSize-1,mid = (numsSize-1)/2;
    int midNew, midTemp;
    int *ret = (int*)malloc(sizeof(int)*2);
    *returnSize = 2;
    if(numsSize==0){
        *ret=-1;*(ret+1) = -1;
        return ret;
    }
    
    if(nums[0]==target){
        *ret = 0;
        if(nums[numsSize-1]==target){
            *(ret+1) = numsSize-1;
            return ret;
        }
        else{
            mid = first;
            goto Loop;
        }    
    }
    if(nums[numsSize-1]==target){
        *(ret+1) = numsSize-1;
        mid = end;
        goto Loop;
    }
    while(end>first){
        if(end-first==1)
            break;
        if(nums[mid]>target){
            end = mid;
            mid = (first+end)/2;
            continue;
        }
        else if(nums[mid]<target){
            first = mid;
            mid = (first+end)/2;
            continue;
        }
        else{
Loop:
            midTemp = mid;
            midNew = (first+mid)/2;
            while(1){
                if(nums[first]==target)
                    break;                
                if((mid-first)==1){
                    *ret = mid;
                    break;
                }
                if(nums[midNew]<target){
                    first = midNew;
                    midNew = (first+mid)/2;
                    continue;
                }
                else if(nums[midNew]==target){
                    mid = midNew;
                    midNew = (first+mid)/2;
                    continue;
                }
            }
            mid = midTemp;
            midNew = (end+mid)/2;
            while(1){       
                if(nums[end]==target)
                    break;         
                if(end-mid==1){
                    *(ret+1) = mid;
                    break;
                }  
                if(nums[midNew]>target){
                    end = midNew;
                    midNew = (end+mid)/2;
                    continue;
                }
                else if(nums[midNew]==target){
                    mid = midNew;
                    midNew = (end+mid)/2;
                    continue;
                }
             
            }
            return ret;
        }
    }
    *ret = -1;*(ret+1) = -1;
    return ret;
}



int main(void){
    int nums[6] = {5,5,6,6,6,7};
    int* ret,retSize = 0;
    ret = searchRange(nums,6,5,&retSize);
    printf("%d %d\n",*ret,*(ret+1));

    return  0;
}