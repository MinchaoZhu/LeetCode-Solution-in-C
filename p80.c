#include <stdio.h>
#include <limits.h>


int removeDuplicates(int* nums, int numsSize) {
    if(numsSize==0)return 0;
    int size = 1;
    int cursor = 1;
    int count = 1;
    int lastNum = nums[0];
    for(;cursor<numsSize;++cursor){
        if(lastNum==nums[cursor]){
            if(count<2){
                nums[size++] = nums[cursor];
                ++count;
            }
        }
        else{
            count = 1;
            lastNum = nums[cursor];
            nums[size++] = nums[cursor];
        }
    }
    return size;
}



int main(void){
    int A[8] = {1,1,1,1,2,2,3,3};
    int size;
    size = removeDuplicates(A,8);

    for(int i = 0;i<size;++i){
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}