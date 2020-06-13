




// less space used
// class Solution {
// public:
//     vector<int> largestDivisibleSubset(vector<int>& nums) {
//         if(nums.size() == 0)
//             return nums;
        
//         sort(nums.begin(), nums.end());
//         vector<int> prev(nums.size(), -1);
//         vector<int> dp(nums.size(), 1);
        
//         int maxLen = 1, maxIndex = 0;
//         for(int i = 1; i < nums.size(); ++i){
//             for(int j = 0; j<i; ++j){
//                 if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1){
//                     dp[i] = dp[j] + 1;
//                     prev[i] = j;
//                 }
//             }
//             if(dp[i] > maxLen){
//                 maxLen = dp[i];
//                 maxIndex = i;
//             }
            
//         }
        
//         vector<int> result;
        
//         while(maxIndex >= 0){
//             result.emplace_back(nums[maxIndex]);
//             maxIndex = prev[maxIndex];
//         }
        
//         return result;
        
//     }
// };





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