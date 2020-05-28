bool isPerfectSquare(int a){
    int tmp = sqrt(a);
    return a == tmp*tmp;
}

int f_min(int a, int b){
    return a<b?a:b;
}

int numSquares(int n){
    if(n<=1){
        return n;
    }
    else{
        int dp[n+1];
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i<=n; ++i){
            if(isPerfectSquare(i)){
                dp[i] = 1;
            }
            else{
                int min = INT_MAX;
                for(int j = 1; j <= sqrt(i); ++j){
                    min = f_min(min, dp[j*j] + dp[i-j*j]);
                }
                dp[i] = min;            
            }
        }
        
        
        return dp[n];
    }
}