class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size()==0)
            return nums;
        sort(nums.begin(), nums.end());
        vector<vector<int>> dp(nums.size(), vector<int>());
        
        dp[0].emplace_back(nums[0]);
        
        
        int maxLen = 0, maxIndex = -1;
        for(int i = 1; i<nums.size(); ++i){
            maxLen = 0, maxIndex = -1;
            for(int j = 0; j<i; ++j){
                if(nums[i] % nums[j] == 0 && maxLen < dp[j].size()){
                    maxLen = dp[j].size();
                    maxIndex = j;
                }
            }
            if(maxIndex>=0) 
                dp[i] = vector<int>(dp[maxIndex]);
            dp[i].emplace_back(nums[i]);
        }
        
        maxLen = 0, maxIndex = -1;
        for(int i = 0; i<dp.size(); ++i){
            if(maxLen<dp[i].size()){
                maxLen = dp[i].size();
                maxIndex = i;
            }
        }
        
        return dp[maxIndex];
        
    }
};