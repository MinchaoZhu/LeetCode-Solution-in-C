
int f_min(int a, int b){
    return a<b?a:b;
}

// DP https://leetcode.com/problems/paint-house/discuss/654301/C-DP-solution-beats-double-100

int minCost(int** costs, int costsSize, int* costsColSize){
    if(costsSize>0){
        int n = *costsColSize;
        int dp[costsSize][3];
        dp[0][0] = costs[0][0];
        dp[0][1] = costs[0][1];
        dp[0][2] = costs[0][2];
        
        for(int i = 1; i<costsSize; ++i){
            dp[i][0] = costs[i][0] + f_min(dp[i-1][1], dp[i-1][2]); 
            dp[i][1] = costs[i][1] + f_min(dp[i-1][0], dp[i-1][2]); 
            dp[i][2] = costs[i][2] + f_min(dp[i-1][0], dp[i-1][1]); 
        }
        
        int min = f_min(dp[costsSize-1][0],dp[costsSize-1][1]);
        min = f_min(min,dp[costsSize-1][2]);
        return min;
    }
    else return 0;
}