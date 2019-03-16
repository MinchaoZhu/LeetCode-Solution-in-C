#include <stdio.h>




int removeElement(int* nums, int numsSize, int val) {
    if(!numsSize)
        return 0;
    if(numsSize == 1){
        if(*nums == val)
            return 0;
        else
            return 1;
    }
    
    int cur0 = 0, cur1 = numsSize - 1;

    do
    {
        while(cur0<numsSize&&*(nums+cur0)!=val){
            ++cur0;
        }
        while(cur1>=0&&*(nums+cur1)==val){
            --cur1;
            --numsSize;
        }
        if(cur0<cur1){
            *(nums+cur0) = *(nums+cur1);
            ++cur0;
            --cur1;
            --numsSize;
        }
        
    } while (cur0<=cur1);
    return numsSize;
}


void printArr(int A[], int size){
    for(int i = 0;i<size;++i){
        printf("%d ", A[i]);
    }
    printf("\n");
}


int main(void){
    int A[3] = {2,2,3};
    int newSize = removeElement(A,3,2);
    printf("%d\n",newSize);
    printArr(A,newSize);

    return 0;
}