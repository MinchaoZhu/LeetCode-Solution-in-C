#include <stdio.h>





int search(int* nums, int numsSize, int target) {
       if (numsSize==1 && nums[0]==target) return 0;
        int left = 0;
        int right = numsSize-1;
        int mid = 0;
        while (left<right){
            mid = (left+right)/2;
            if (nums[left]==target) return left;
            if (nums[right]==target) return right;
            if (nums[mid]==target) return mid;
            if (nums[mid] > nums[left]){ //第一种情况
                if (target>nums[mid]) {
                    left = mid+1;
                }else {
                    if (target>nums[left]) {
                        right = mid-1;
                    }else {
                        left = mid+1;
                    }
                }
            }else { //第二种情况
                if (target>nums[mid]){
                    if (target<nums[right]) {
                        left = mid + 1;
                    }else {
                        right = mid -1;
                    }
                }else {
                    right = mid -1;
                }
            }
 
        }
        return -1;
}

int main(void){


    
}