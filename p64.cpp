#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int i;
        for(i = m-2;i>=0;--i){
            grid[i][n-1] = grid[i][n-1] + grid[i+1][n-1];
        }
        for(i = n-2;i>=0;--i){
            grid[m-1][i] = grid[m-1][i] + grid[m-1][i+1];
        }
        --m;--n;
        while(m>0&&n>0){
            for(i = m-1;i>=0;--i){
                grid[i][n-1] = grid[i][n-1] + ((grid[i+1][n-1]<grid[i][n])?grid[i+1][n-1]:grid[i][n]);
            }
            for(i = n-2;i>=0;--i){
                grid[m-1][i] = grid[m-1][i] + ((grid[m-1][i+1]<grid[m][i])?grid[m-1][i+1]:grid[m][i]);
            }
            --m;--n;
        }
        return grid[0][0];
    }
};



int main(void){
    vector<vector<int>> v = {{4,3,1},{1,5,1},{4,2,1}};
    Solution s;
    int i;
    i = s.minPathSum(v);
    cout<<i<<endl;


}