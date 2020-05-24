int quickSolve(int* prices, int len) {
        int profit = 0;
        for (int i = 1; i < len; i++)
            // as long as there is a price gap, we gain a profit.
            if (prices[i] > prices[i - 1]) profit += prices[i] - prices[i - 1];
        return profit;
}

// DP

// dp[i][j]: 在j天结束的时候至多执行了i次交易获得的最大利润
// balance: 在第j天之前, 在某一天至多执行了i-1次交易, 并且在另一天购入了股票后的最大收支余额

int maxProfit(int k, int* prices, int pricesSize){
    if(pricesSize>1&&k>0){
        if(k>(pricesSize<<1)){
            return quickSolve(prices, pricesSize);
        }
        int dp[k][pricesSize];
        int min = prices[0];
        dp[0][0] = 0;
        for(int j = 1; j<pricesSize; ++j){
            min = min<prices[j]?min:prices[j];
            dp[0][j] = dp[0][j-1] > (prices[j] - min)?dp[0][j-1]:(prices[j] - min);
        }

        for(int i = 1; i < k; ++i){
            dp[i][0] = 0;
            int balance = 0-prices[0]; 
            for(int j = 1; j<pricesSize; ++j){
                dp[i][j] = dp[i][j-1]>balance+prices[j]?dp[i][j-1]:balance+prices[j];//取前一天结果VS在这一天卖掉
                balance = balance > (dp[i-1][j-1] - prices[j])?balance:(dp[i-1][j-1] - prices[j]);//为下一天可能的卖出股票更新一下余额    
            }    
        }
        return dp[k-1][pricesSize-1];
    }
    else return 0;
}

