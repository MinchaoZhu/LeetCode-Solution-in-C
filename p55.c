#include <stdio.h>
#include <stdbool.h>


bool canJump(int* nums, int numsSize) {
        int next=0;
        for(int i=0;i<numsSize;i++){
            if(next>=numsSize-1) return true;
            if(i==next) {
                if(nums[i]==0) return false;
                next=nums[i];
            }
            if(i+nums[i]>next) next=i+nums[i];
        }
        return true;
}

int main(void){



    return 0;
}