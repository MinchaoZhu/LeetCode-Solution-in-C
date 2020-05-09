#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
//     int uniquePathsWithObstacles(vector<vector<int>>& table0) {
//         int m = table0.size(), n = table0[0].size(),i;
//         long table[m][n];
//         for(i = 0;i<m;++i){
//             for(int j = 0;j<n;++j){
//                 table[i][j] = table0[i][j];
//             }
//         }
//         if(table[m-1][n-1]==0)
//                 table[m-1][n-1] = 1;
//         else return 0;
//         for(i = m-2;i>=0;--i){
//                 if(table[i][n-1]!=1)
//                         table[i][n-1] = table[i+1][n-1];
//                 else
//                         table[i][n-1] = 0;
//         }
//         for(i = n-2;i>=0;--i){
//                 if(table[m-1][i]!=1)
//                         table[m-1][i] = table[m-1][i+1];
//                 else
//                         table[m-1][i] = 0;
//         }
//         if(m==1||n==1)return table[0][0];
//         --m;--n;
//         while(m>0&&n>0){
//                 for(i = m-1;i>=0;--i){
//                         if(table[i][n-1]!=1)
//                                 table[i][n-1] = table[i+1][n-1]+table[i][n];
//                         else
//                                 table[i][n-1] = 0;        
//                 }
//                 for(i = n-2;i>=0;--i){
//                         if(table[m-1][i]!=1)
//                                 table[m-1][i] = table[m][i]+table[m-1][i+1];
//                         else
//                                 table[m-1][i] = 0;  
//                 }
//                 --m;--n;
//         }
//     return table[0][0];
//     }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int dp[m][n];
        dp[0][0] = !obstacleGrid[0][0];
        for(int i = 1; i<m; ++i){
           dp[i][0] = !obstacleGrid[i][0]&&dp[i-1][0];     
        }
        for(int j = 0; j<n; ++j){
           dp[0][j] = !obstacleGrid[0][j]&&dp[0][j];  
        }
        for(int i = 1; i<m; ++i){
            for(int j = 1; j<n; ++j){
                dp[i][j] = obstacleGrid[i][j]==1?0:dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }


};

int main(void){
    vector<vector<int>> t = {{0,1},{0,0},{0,0},{0,0},{0,0},{1,0},{0,0},{0,0}};
    
    //vector<vector<int>> t = {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{1,0},{0,0},{0,0},{0,0},{0,0},{0,0},{1,0},{0,0},{0,0},{0,0},{0,0},{0,1},{0,0}};
    int i;
    Solution s;
    i = s.uniquePathsWithObstacles(t);
    cout<<i<<endl;

    return 0;
}