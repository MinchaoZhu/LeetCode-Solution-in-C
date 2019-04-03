#include <stdio.h>
#include <stdbool.h>


bool canJump(int* nums, int numsSize) {
    bool posValid[numsSize-1];
    bool valid = 0;
    int pos = numsSize-2;
    int i = 0;
    for(;pos>=0;--pos){
        posValid[pos] = 0;
        if(!nums[pos])
            continue;
        for(i = 1;i<nums[pos]+1;++i){
            if(pos+i>=numsSize-1){
                posValid[pos] = 1;
                break;
            }
            if(posValid[pos+i]){
                posValid[pos] = 1;
                break;
            }
        }
    }
    return posValid[0];
}

int main(void){



    return 0;
}