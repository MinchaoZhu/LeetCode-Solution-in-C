#include <stdio.h>





int removeDuplicates(int* nums, int numsSize) {
    if(numsSize<2)
        return numsSize;
    int preNum = *nums,nowNum, newSize = 1;
    for(int i = 1;i<numsSize;++i){
        nowNum = *(nums+i);
        if(nowNum!=preNum){
            *(nums+newSize) = nowNum;
            ++newSize;
            preNum = nowNum;
        }
    }
    return newSize;
}




int main(void){
    int A[10] = {0,0,1,1,1,2,2,3,3,4};
    int newSize = 0;
    newSize = removeDuplicates(A,10);
    for(int i = 0;i<newSize;++i){
        printf("%d ",A[i]);
    }
    printf("\n");

    return 0;
}