#include <stdio.h>
#include <string.h>
#include <stdbool.h>


/**
 * DP solution
 * < l1, l2, l3 are length of s1, s3 and s3 >
 * < s[i,j] means substring from s[i] to s[j], where s[j] is included. >
 * 
 * 
 * Define a sub-problem f(m,n):
 *    Is s3[m+n, l3-1] interleaving of s1[m, l1-1] and s2[n, l2-1]?
 * We try to solve this problem and obviously f(0,0) is the final result.
 * 
 * Base case:
 *  1. f(l1, l2) = true  : empty INTER empty -> empty
 *  2. f(m, l2) = (s3[l3-l1+m, l3-1] == s1[m, l1-1]) : subtring of s1 ?=  substring of s3   
 *  3. f(l1, n) = (s3[l3-l2+n, l3-1] == s2[n, l2-1]) : subtring of s2 ?=  substring of s3  
 * Then we try to find recursion formula.
 * 
 * We try to seek it from a example:
 *   s1 = aaa  
 *   s2 = bbb 
 *   s3 = ababab
 *   try to find f(1,1) : is  aa INTER bb  == abab ?
 *   Answer is true.
 *   Obviously f(2,1) is true : a INTER bb -> bab
 *             f(1,2) is false: aa INTER b !-> bab
 *   If we compare first char of sub_s1 or sub_s2 with sub_s3 and combine the result of remaining strings, 
 *   we can know f(1,1) is true or false.
 *   a = a and f(2,1) is true --> f(1,1) is true
 *   Because there are s1 and s2, so repeat the comparison by extract the first char of sub_s3:
 *   b != a and f(1,2) is false --> false 
 * 
 * Hence the recursion formula is
 *   f(m,n) =  ((s1[m]==s3[m+n]) and f(m+1, n))
 *          or ((s2[n]==s3[m+n]) and f(m, n+1))
 * 
 * */

bool isInterleave(char * s1, char * s2, char * s3){
    int l1 = strlen(s1), l2 = strlen(s2), l3 = strlen(s3);
    if(l1+l2==l3){
        bool dp[l1+1][l2+1];
        dp[l1][l2] = 1; // empty INTER empty -> empty : true
        for(int m = 0; m<l1; ++m){
            dp[m][l2] = !(strcmp(s1+m, s3+(l3-l1+m))); // substring of s1 ?= substring of s3
        }
        for(int n = 0; n<l2; ++n){
            dp[l1][n] = !(strcmp(s2+n, s3+(l3-l2+n))); // substring of s2 ?= substring of s3
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