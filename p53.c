#include <stdio.h>


// int maxSubArray(int* nums,int numsSize) {
//         int max = nums[0];
//         int sum = 0;
//         for (int i = 0;i<numsSize;++i) {
//             sum = sum>0?sum:0;
//             sum += nums[i];
//             max = max>sum?max:sum;
//         }
//         return max;
// }



// DP
int maxSubArray(int* nums, int numsSize){
    int max[numsSize]; // maxSubArray (nums[0:i])
    int tail[numsSize]; // max sum of subArray (nums[k, i]), means from nums[i] calculate the max sum back until nums[0]
    tail[0] = nums[0];
    max[0] = nums[0];
    // We try to find max[numsSize] which is result
    // recursion formula
    // tail:
    //  if tail[i-1] < 0, tail[i] = nums[i]
    //  else tail[i] = tail[i-1] + nums[i]
    // max:
    //  tail[i] or max[i-1]( which means maxSubArray is inner nums[0, i] )

    for(int i = 1; i<numsSize; ++i){
        tail[i] = nums[i] + (tail[i-1]>0?tail[i-1]:0);
        max[i] = max[i-1]>tail[i]?max[i-1]:tail[i];
    }
    return max[numsSize-1];
}


int main(void){
    int a[2] = {-2,-1};
    int max;
    max = maxSubArray(a,2);
    printf("%d\n",max);
    return 0;
}