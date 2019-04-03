#include <stdio.h>


int maxSubArray(int* nums,int numsSize) {
        int max = nums[0];
        int sum = 0;
        for (int i = 0;i<numsSize;++i) {
            sum = sum>0?sum:0;
            sum += nums[i];
            max = max>sum?max:sum;
        }
        return max;
}


int main(void){
    int a[9] = {-2,1,-3,4,-1,2,1,-5,4};
    int max;
    max = maxSubArray(a,9);
    printf("%d\n",max);
    return 0;
}