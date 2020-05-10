#include <string.h>
#include <stdio.h>




int minDistance(char * word1, char * word2){
    int len1 = strlen(word1), len2 = strlen(word2);
    int dp[len1+1][len2+1];
    /**
     * dp[i][j]  => min distance from word1[0, i-1] to word2[0, j-1]
     * dp[0][0]  => empty to empty
     * In order to solve dp[len1][len2] which is what we need, find recursion formula
     * case1:
     *    if word1[i-1] = word[j-1]
     *      Need no change, hence dp[i][j] = dp[i-1][j-1]
     * case2:
     *    if word1[i-1] != word[j-1]
     *    There are three ways can we translate word1[0, i-1]  to word2[0, j-1]
     *    I. delete word1[i-1], translate word1[0, i-2] to word2[0, j-1]
     *      dp[i][j] = dp[i-1][j] + 1;
     *    II. delete word2[j-1],  then translate word1[0, i-1] to word2[0, j-2]
     *      dp[i][j] = dp[i][j-1] + 1;
     *    III. replace word1[i-1] by word2[j-1]
     *      dp[i][j] = dp[i-1][j-1] + 1;      
     *    Among those three ways we choose the one results in minimum dp[i][j] 
     * */
    dp[0][0] = 0;
    for(int i = 1; i<=len1; ++i){
        // word1[0,i-1] -> empty :  i
        dp[i][0] = i;
    }
    for(int j = 1; j<=len2; ++j){
        // empty -> word2[0,j-1]
        dp[0][j] = j;
    }

    for(int i = 1; i <=len1; ++i){
        for(int j = 1; j<=len2; ++j){
            if(word1[i-1]==word2[j-1]){
                dp[i][j] = dp[i-1][j-1]; // need no edit
            }
            else{
                int d1 = dp[i-1][j] + 1; // delete word1[i-1]
                int d2 = dp[i][j-1] + 1; // delete word2[i-1]
                int d3 = dp[i-1][j-1] + 1; // replace word1[i-1] by word2[i-1]
                d1 = d1<d2?d1:d2;
                d1 = d1<d3?d1:d3;
                dp[i][j] = d1;
            }
        }
    }
    return dp[len1][len2];
}


int main(void){
    char* w1 = "horse";
    char* w2 = "ros";
    int t = minDistance(w1, w2);
    printf("%d\n", t);
    return 0;
}