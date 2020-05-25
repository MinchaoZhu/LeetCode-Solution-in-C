int rob(int* nums, int numsSize){
    if(numsSize>0){
        int dp[numsSize];
        dp[0] = nums[0];
        for(int i = 1; i<numsSize; ++i){
            int tmp1 = dp[i-1];
            int tmp2 = nums[i];
            if(i>=2) tmp2 += dp[i-2];
            dp[i] = tmp1>tmp2?tmp1:tmp2;
        }
        return dp[numsSize-1];
    }
    else return 0;
}