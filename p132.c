#include <stdbool.h>


int minCut(char * s){
    int len = strlen(s);
    if(len>1){
        int dp[len];
        bool p[len][len];
        for(int i = 0; i<len; ++i){
            p[i][i] = true;
        }
        for(int i = 0; i<len-1; ++i){
            p[i][i+1] = s[i]==s[i+1];
        }
        for(int l = 3; l<=len; ++l){
            for(int i = 0; i<=len-l; ++i){
                p[i][i+l-1] = p[i+1][i+l-2]&&s[i] == s[i+l-1];
            }
        }
        
        dp[0] = 0;
        for(int i = 1; i<len; ++i){
            int min = p[0][i]?0:i;
            for(int j = 1;j<=i; ++j){
                if(p[j][i]){
                    min = min<dp[j-1]+1?min:dp[j-1]+1;
                }
            }
            dp[i] = min;
        }
        return dp[len-1];
    }
    else return 0;
}