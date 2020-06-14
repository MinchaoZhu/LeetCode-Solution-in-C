class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<pair<int,int>>> g(n, vector<pair<int,int>>()); // records the in-edges rather than out-edges
        for(auto f : flights){
            g[f[1]].emplace_back(pair<int,int>(f[0], f[2]));
        }
        
        vector<vector<int>> dp(K+2, vector<int>(n, INT_MAX));
        dp[0][src] = 0;
        
        for(int i = 1; i<K+2&&i<=n; ++i){
            for(int j = 0; j < n; ++j){
                int tmp = dp[i-1][j];
                for(auto e : g[j]){
                    if(tmp - dp[i-1][e.first] > e.second){
                        tmp = dp[i-1][e.first] + e.second;
                    }
                }
                dp[i][j] = tmp;
            }
        }
        
        return dp[K+1][dst] == INT_MAX?-1:dp[K+1][dst];
        
        
        
    }

    
};