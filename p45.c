#include <stdio.h>
#include <string.h>

int findMin(int* nums, int numsSize, int * min, int pos){
    int val = 1, step = numsSize;
    for(;val<=*(nums+pos);++val){
        if(pos+val>=numsSize)
            break;
        if(step>*(min+pos+val))
            step = *(min+pos+val);
    }
    return step+1;
}

int jump(int* nums, int numsSize) {
    int min[numsSize];
    min[numsSize-1] = 0;
    int pos;
    for(pos = numsSize-2;pos>=0;--pos){
        *(min+pos) = findMin(nums,numsSize,min,pos);
    }
    return *min;
}




int main(void){
    int A[39] = {5,6,4,4,6,9,4,4,7,4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9,4,1,6,8,8,4,4,2,0,3,8,5};
    int x;
    //int A[5] = {2,3,1,1,4};
    x = jump(A,39);
    printf("%d\n",x);

    return 0;
}