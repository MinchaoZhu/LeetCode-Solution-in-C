#include <stdio.h>
#include <string.h>
#include <stdbool.h>


bool isInterleave(char * s1, char * s2, char * s3){
    int l1 = strlen(s1), l2 = strlen(s2), l3 = strlen(s3);
    if(l1+l2==l3){
        bool dp[l1+1][l2+1];
        dp[l1][l2] = 1;
        for(int m = 0; m<l1; ++m){
            dp[m][l2] = !(strcmp(s1+m, s3+(l3-l1+m)));
        }
        for(int n = 0; n<l2; ++n){
            dp[l1][n] = !(strcmp(s2+n, s3+(l3-l2+n)));
        }
        for(int m = l1-1; m>=0; --m){
            for(int n = l2-1; n>=0; --n){
                dp[m][n] = ((s1[m]==s3[m+n])&&dp[m+1][n])||((s2[n]==s3[m+n])&&dp[m][n+1]);
            }
        }
        return dp[0][0];
    }
    return false;
}


int main(void){
    char * s1 = "aabcc",
         * s2 = "dbbca",
         * s3 = "aadbbbaccc";
    int t;
    t = isInterleave(s1,s2,s3);
    printf("%d\n",t);
    return 0;
}