#include <stdio.h>
#include <stdbool.h>


bool canJump(int* nums, int numsSize) {
    int maxDistance = 0;//the maxDistance we can reach before present position.
    int pos = 0;
    for(;pos<numsSize;++pos){
        if(maxDistance>=numsSize-1)
            return 1;
        if(pos==maxDistance){
            if(!nums[pos])//the fareset distance is not the end, so array is invalid.
                return 0;
            else{
                maxDistance = pos+nums[pos];
            }
        }
        else{
            maxDistance = maxDistance>pos+nums[pos]?maxDistance:pos+nums[pos];
        }
    }
    return 1;
}

int main(void){
    int a[5] = {4,3,2,0,4};
    int x;
    x = canJump(a,5);
    printf("%d\n",x);

    return 0;
}