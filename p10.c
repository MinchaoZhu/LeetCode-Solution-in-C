#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool isMatch(char * s, char * p){
    int sLen = strlen(s), pLen = strlen(p);
    bool dp[sLen+1][pLen+1];
    dp[0][0] = true;
    //s[0,i-1] matching empty string
    for(int i = 1; i<=sLen;++i){ 
        dp[i][0] = false;
    }
    //empty string matching p[0,j-1]
    for(int j = 1; j<=pLen;++j){
        dp[0][j] = false;
        if(p[j-1]=='*'&&j>=2){
            dp[0][j] = dp[0][j-2];
        }
    }

    //s[0,i-1] matching p[0, j-1]
    for(int i = 1; i<=sLen; ++i){
        for(int j = 1; j<=pLen; ++j){
            dp[i][j] = false;
            //if p[j-1] is *
            if(p[j-1]=='*'&&j>=2){
                if(s[i-1] != p[j-2] && p[j-2] != '.'){
                    // if a in 'a*' doesn't match 
                    // 'a*' repeats zero times, and should match s[0,i-1] and p[0, j-3]
                    if(j>=3){
                        dp[i][j] = dp[i][j-2];
                    }
                }
                else{
                    bool flag = false;
                    flag = flag || dp[i][j-2];// 'a*' repeats 0 times
                    flag = flag || dp[i-1][j-1];// 'a*' repeats 1 time
                    flag = flag || dp[i-1][j];// 'a*' repeats multiple times 
                    dp[i][j] = flag;
                }
            }
            else if(p[j-1]=='.'){
                if(i>=1)
                    dp[i][j] = dp[i-1][j-1];
            }
            else{//if p[j-1] is alphabet char
                if(i>=1)
                    dp[i][j] = dp[i-1][j-1]&&(s[i-1]==p[j-1]);
            }
        }
    }
    return dp[sLen][pLen];
}

int main(void){
    char * s = "aasdfasdfasdfasdfas";
    char * p = "aasdf.*asdf.*asdf.*asdf.*s";
    int t = isMatch(s,p);
    printf("%d\n",t);
    return 0;
}