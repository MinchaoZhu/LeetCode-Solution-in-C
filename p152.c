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

// DP 

// int maxProduct(int* nums, int numsSize){
//     if(numsSize>0){
//         int dp[numsSize];
//         int borderMax[numsSize];
//         int borderMin[numsSize];
//         dp[0] = nums[0];
//         borderMax[0] = nums[0];
//         borderMin[0] = nums[0];
//         for(int i = 1; i<numsSize; ++i){
//             int tmp1 = borderMax[i-1] * nums[i];
//             int tmp2 = borderMin[i-1] * nums[i];
//             int tmp = tmp1;
//             if(tmp1<tmp2){
//                 tmp1 = tmp2;
//                 tmp2 = tmp;
//             }
//             tmp1 = tmp1>nums[i]?tmp1:nums[i];
//             tmp2 = tmp2<nums[i]?tmp2:nums[i];
//             borderMax[i] = tmp1;
//             borderMin[i] = tmp2;
//             dp[i] = tmp1>dp[i-1]?tmp1:dp[i-1];
//         }
//         return dp[numsSize-1];
//     }
//     else return 0;
// }