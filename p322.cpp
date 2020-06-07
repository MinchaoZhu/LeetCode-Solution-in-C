class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;
        for(auto& c : coins){
            if(c<=amount)
                dp[c] = 1;
        }
        for(int i = 1; i<=amount; ++i){
            int tmp = dp[i];
            for(auto& c: coins){
                if(i-c>0&&dp[i-c]!=INT_MAX){
                    tmp = min(tmp, dp[i-c]+1);
                }
            }
            dp[i] = tmp;
        }
        
        return dp[amount]==INT_MAX?-1:dp[amount];
    }
};