#include <stdlib.h>
#include <stdio.h>




/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* grayCode(int n, int* returnSize){
    int *result = (int*)malloc(sizeof(int)*(1<<n));
    *returnSize = 1<<n;
    for(int i = 0;i<*returnSize;++i){
        result[i] = i^(i>>1);
    }
    return result;
}




int main(void){



    return 0;
}