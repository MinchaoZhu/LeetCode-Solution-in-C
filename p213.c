//https://leetcode.com/problems/house-robber-ii/discuss/651813/C-0ms-DP-solution-based-on-Problem-198.-House-Robber

int robHelper(int* nums, int numsSize){
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


int rob(int* nums, int numsSize){
    int tmp1 = robHelper(nums, numsSize-1);
    int tmp2 = robHelper(nums+1, numsSize-1);
    int tmp3 = robHelper(nums+1, numsSize-2);
    
    tmp1 = tmp1>tmp2?tmp1:tmp2;
    tmp1 = tmp1>tmp3?tmp1:tmp3;
    if(numsSize==1)
        tmp1 = tmp1>nums[0]?tmp1:nums[0];
    return tmp1;
}