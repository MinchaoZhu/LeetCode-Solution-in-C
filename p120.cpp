#include <vector>
#include <limits>
#include <iostream>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        vector<int> result(t.size(),0);
        result[0] = t[0][0];
        int pre,pre2;
        for(int i = 1;i<t.size();++i){
            pre = result[0];
            result[0] += t[i][0];
            for(int j = 1;j<i;++j){
                pre2 = result[j];
                result[j] = t[i][j] + (pre<pre2?pre:pre2);
                pre = pre2;
            }
            result[i] = pre+t[i][i];
        }

        int min = 10000;
        for(int i = 0;i<t.size();++i){
            min = result[i]<min?result[i]:min;
        }
        return min;
    }
};

// [C] DP

// int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){
    // if(triangleSize>0){
        // int dp[triangleSize][triangleSize];
        // dp[0][0] = triangle[0][0];
        // for(int i = 1; i < triangleSize; ++i){
            // dp[i][0] = dp[i-1][0] + triangle[i][0];
            // dp[i][i] = dp[i-1][i-1] + triangle[i][i];
            // for(int j = 1; j < i; ++j){
                // int tmp1 = dp[i-1][j-1], tmp2 = dp[i-1][j];
                // dp[i][j] = triangle[i][j] + (tmp1<tmp2?tmp1:tmp2);
            // }
        // }
        // int min = dp[triangleSize-1][0];
        // for(int j = 1; j<triangleSize; ++j){
            // min = min<dp[triangleSize-1][j]?min:dp[triangleSize-1][j];
        // }
        // return min;
    // }
    // else return 0;
// }


int main(void){
    vector<vector<int>> t = {{2},{3,4},{6,5,7},{4,1,8,3}};
    Solution s;
    int min = s.minimumTotal(t);
    cout << min << endl;
}