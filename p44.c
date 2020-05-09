#include <stdio.h>
#include <string.h>
#include <stdbool.h>


bool isMatch(char * s, char * p){
    int sLen = strlen(s), pLen = strlen(p);
    bool dp[sLen+1][pLen+1]; // dp[i][j] = match( s[0, i-1] and p[0, j-1] )
    dp[0][0] = true; // match( empty, empty) is true
    for(int i = 1; i<sLen+1; ++i){
        dp[i][0] = false;// match( s[0, i-1], empty ) is false
    }
    for(int j = 1; j<pLen+1; ++j){
        dp[0][j] = p[j-1]=='*'?dp[0][j-1]:false;       //macth( empty, p[0, j-1])
    }

    for(int i = 1; i<sLen+1; ++i){
        for(int j = 1; j<pLen+1; ++j){
            if(p[j-1]=='?'){
                dp[i][j] = dp[i-1][j-1];
            }
            else if(p[j-1]=='*'){
                bool flag = false;
                flag |= dp[i][j-1];// * -> empty
                flag |= dp[i-1][j-1];// * -> one character
                flag |= dp[i-1][j];// * -> a string
                dp[i][j] = flag;
            }
            else{
                dp[i][j] = dp[i-1][j-1] && p[j-1]==s[i-1];
            }
        }
    }

    return dp[sLen][pLen];

}



int main(void){
    char* s = "zacabz";
    char* p = "*a?b*";
    int r = isMatch(s,p);
    printf("%d\n", r);

    return 0;
}