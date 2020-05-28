int f_min(int a, int b){
    return a<b?a:b;
}

int minCostII(int** costs, int costsSize, int* costsColSize){
    if(costsSize>0){
        int n = costsSize, k = *costsColSize;
        if(n>0){
            int dp[n][k];
            for(int j = 0; j<k; ++j){
                dp[0][j] = costs[0][j];
            }
            for(int i = 1; i<n; ++i){
                for(int j = 0; j<k; ++j){
                    int min = INT_MAX;
                    for(int t = 1; t<k; ++t){
                        min = f_min(min, dp[i-1][(j+t)%k]);
                    }
                    dp[i][j] = costs[i][j] + min;
                }    
            }
            
            int result = INT_MAX;
            for(int j = 0; j<k; ++j){
                result = f_min(dp[n-1][j], result);
            }
            
            return result;
        }
        return 0;
    }
    else return 0;
}