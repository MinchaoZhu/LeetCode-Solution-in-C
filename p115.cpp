#include <vector>
#include <string>
#include <iostream>
using namespace std;



class Solution {
public:
    int numDistinct(string s, string t) {
        int sLen=s.length(),tLen = t.length();
        unsigned long table[tLen];for (int i = 0; i < tLen; i ++) table[i] = 0;
        for(int i=0;i<sLen;++i){
            for(int j=tLen-1;j>=0;--j){
                if(s[i]==t[j]){
                    if(j==0)++table[0];
                    else table[j]+=table[j-1];
                }
            }
        }
        return table[tLen-1];
    }
};


// [C]DP 
// comments: https://leetcode.com/problems/distinct-subsequences/discuss/644686/C-DP-solution-with-example
// int numDistinct(char * s, char * t){
//     int l1 = strlen(s), l2 = strlen(t);
//     if(l2==0)
//         return 1;
//     else if(l1>=l2){
//         unsigned long dp[l1][l2];
//         dp[0][0] = s[0]==t[0];
//         for(int j = 1; j<l2; ++j){
//             dp[j][j] = dp[j-1][j-1] && s[j]==t[j];
//         }
//         for(int j = 0; j<l2; ++j){
//             for(int i = j+1; i<l1; ++i){
//                dp[i][j] = dp[i-1][j] + (s[i]==t[j]?(j>0?dp[i-1][j-1]:1):0);
//             }
//         }
//         return dp[l1-1][l2-1];
//     }
//     else
//         return 0;
// }



int main(void){
    string s = "rabbbit";
    string t = "rabbit";
    int i=0;
    Solution ss;
    i = ss.numDistinct(s,t);
    cout<<i<<endl;

    return 0;
}