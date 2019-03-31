#include <stdio.h>


int dfs(int* nums, int numsSize, int pos){
    if(pos == numsSize-1)
        return 0;
    int i,min = numsSize,step;
    for(i = 1;i<*(nums+pos)+1;++i){
        if(pos+i>=numsSize)
            break;
        step = dfs(nums,numsSize,pos+i);
        if(step<min)
            min = step;
    }
    return min+1;
}

int jump(int* nums, int numsSize) {
    return dfs(nums,numsSize,0);
}




int main(void){
    int A[39] = {5,6,4,4,6,9,4,4,7,4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9,4,1,6,8,8,4,4,2,0,3,8,5};
    int x;
    x = jump(A,39);
    printf("%d\n",x);

    return 0;
}