#include <stdlib.h>

typedef struct{
    int max;
    int min;
}product;

int maxProduct(int* nums, int numsSize){
    if(numsSize>0){
        product* table = (product*)malloc(sizeof(product)*numsSize);
        table[numsSize-1].max = nums[numsSize-1];
        table[numsSize-1].min = nums[numsSize-1];
        int temp0, temp1;
        for(int i = numsSize-2;i>=0;--i){
            temp0 = nums[i]*table[i+1].max;
            temp1 = nums[i]*table[i+1].min;
            table[i].max = temp1>(nums[i]>temp0?nums[i]:temp0)?temp1:(nums[i]>temp0?nums[i]:temp0);
            table[i].min = temp1<(nums[i]<temp0?nums[i]:temp0)?temp1:(nums[i]<temp0?nums[i]:temp0);
        }
        int result = table[0].max;
        for(int i =1;i<numsSize;++i) result = result>table[i].max?result:table[i].max;
        free(table);
        return result;
    }
    else return 0;
}

