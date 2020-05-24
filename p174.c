
// dp  bottom to top, right to left

int calculateMinimumHP(int** dungeon, int dungeonSize, int* dungeonColSize){
    if(dungeonSize>0){
        int m = dungeonSize, n = dungeonColSize[0];
        if(n>0){
            int dp[m][n];
            int** d = dungeon;
            dp[m-1][n-1] = d[m-1][n-1]>=0?1:1-d[m-1][n-1];

            for(int i = m-2; i>=0; --i){
                int tmp = dp[i+1][n-1] - d[i][n-1];
                dp[i][n-1] = tmp<=0?1:tmp;
            }
            for(int j = n-2; j>=0; --j){
                int tmp = dp[m-1][j+1] - d[m-1][j];
                dp[m-1][j] = tmp<=0?1:tmp;
            }

            for(int i = m-2; i>=0; --i){
                for(int j = n-2; j>=0; --j){
                    int tmp = 0-d[i][j];
                    tmp += dp[i][j+1]<dp[i+1][j]?dp[i][j+1]:dp[i+1][j];    
                    dp[i][j] = tmp<=0?1:tmp;
                }
            }
            return dp[0][0];
        }
        else return 0;
    }
    else return 0;
}