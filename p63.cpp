#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& table0) {
        int n = table0.size(), m = table0[0].size(),i;
        long obstacleGrid[n][m];
        for(i = 0;i<n;++i){
            for(int j = 0;j<m;++j){
                obstacleGrid[i][j] = table0[i][j];
            }
        }
        if(m==0 || obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1) return 0;
        
        obstacleGrid[n-1][m-1] = 1;
        for(int j=m-1;j>=0;j--) { 
            for(int i=(j==m-1)?n-2:n-1; i>=0; i--) {
                if(--obstacleGrid[i][j] == -1) {
				   // unary ? takes care of boundary conditions.
                    obstacleGrid[i][j] = (i==n-1 ? 0 : obstacleGrid[i+1][j]) + 
                                         (j==m-1 ? 0 : obstacleGrid[i][j+1]);
                }
            }
        }
        
        return obstacleGrid[0][0];
    }
};

int main(void){
    vector<vector<int>> t = {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{1,0},{0,0},{0,0},{0,0},{0,0},{0,0},{1,0},{0,0},{0,0},{0,0},{0,0},{0,1},{0,0},{0,0},{1,0},{0,0},{0,0},{0,1},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,1},{0,0},{0,0},{0,0},{0,0},{1,0},{0,0},{0,0},{0,0},{0,0}};
    int i;
    Solution s;
    i = s.uniquePathsWithObstacles(t);
    cout<<i<<endl;

    return 0;
}