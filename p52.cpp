#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        vector<string> sol;
        string t(n,'.');
        for(int i = 0;i<n;++i){
            sol.push_back(t);
        }
        int total = 0;
        dfs(total,sol,n,0);
        return total;
    }
private:
    void dfs(int& total, vector<string>& sol, int n, int level){
        if(level>=n){
            ++total;
            return;
        }
        for(int y = 0;y<n;++y){
            if(isSafe(sol,level,y)){
                sol[level][y] = 'Q';
                dfs(total,sol,n,level+1);
                sol[level][y] = '.';
            }
        }
    }

    bool isSafe(vector<string>const sol, int newx, int newy)const{
        int n = sol.size();
        for(int i = 0;i<n;++i){//check row
            if(sol[newx][i]=='Q')
                return 0;
        }
        for(int i = 0;i<n;++i){//check col
            if(sol[i][newy]=='Q')
                return 0;
        }
        int x = newx-1,y = newy+1;
        while(x>=0&&y<=n-1){
            if(sol[x][y]=='Q')
                return 0;
            --x;
            ++y;
        }
        x = newx+1;y = newy-1;        
        while(x<=n-1&&y>=0){
            if(sol[x][y]=='Q')
                return 0;
            ++x;
            --y;
        }
        x = newx+1;y = newy+1;        
        while(x<=n-1&&y<=n-1){
            if(sol[x][y]=='Q')
                return 0;
            ++x;
            ++y;
        }
        x = newx-1;y = newy-1;        
        while(x>=0&&y>=0){
            if(sol[x][y]=='Q')
                return 0;
            --x;
            --y;
        }
        return 1;
    }
};


int main(void){
    Solution s;
    int result;
    result = s.totalNQueens(16);
    cout<<result<<endl;
    return 0;
}