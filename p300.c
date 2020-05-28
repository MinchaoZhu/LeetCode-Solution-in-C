

int lengthOfLIS(int* nums, int numsSize){
    if(numsSize>1){
        int dp[numsSize];
        dp[0] = 1;
        int result = 0;
        for(int i = 1; i<numsSize; ++i){
            int max = 1;
            for(int j = 0; j<i; ++j){
                if(nums[j]<nums[i]){
                    max = (max>dp[j]+1)?max:(dp[j]+1);    
                }
            }
            dp[i] = max;
            result = result > max ? result : max;
        }
        return result;
        
    }
    else return numsSize;
}