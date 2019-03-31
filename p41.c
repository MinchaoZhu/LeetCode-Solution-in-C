#include <stdio.h>
#include <stdlib.h>


int cmp(const void * a, const void * b){
    return *(int*)a>*(int*)b;
}



int firstMissingPositive(int* nums, int numsSize) {
    if(numsSize==0)
        return 1;
    else if(numsSize==1){
        return *nums>1?1:((*nums==1)?2:1);
    }
    qsort(nums,numsSize,4,cmp);
    int i = 0;
    while(*(nums+i)<1){
        ++i;
        if(i>=numsSize) return 1;
    }
    if(*(nums+i)>1)
        return 1;
    ++i;
    for(;i<numsSize;++i){
        if(*(nums+i)-*(nums+i-1)>1)
            return *(nums+i-1)+1;
    }
    return *(nums+numsSize-1)+1;
}

int main(void){
    int a[4] = {3,4,-1,1};
    int i = firstMissingPositive(a,4);
    printf("%d\n",i);
    return 0;    
}