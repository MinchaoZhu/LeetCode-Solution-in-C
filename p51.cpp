#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> sol;
        string t(n,'.');
        for(int i = 0;i<n;++i){
            sol.push_back(t);
        }
        dfs(result,sol,n,0);
        return result;
    }
private:
    void dfs(vector<vector<string>>& result, vector<string>& sol, int n, int level){
        if(level>=n){
            result.push_back(sol);
            return;
        }
        for(int y = 0;y<n;++y){
            if(isSafe(sol,level,y)){
                sol[level][y] = 'Q';
                dfs(result,sol,n,level+1);
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

void printChess(vector<vector<string>>& v) {
    int size = v.size();
    int n = v[0].size();
    vector<string> s;
    for(int i = 0;i<size;++i){
        s = v[i];
        for(int j = 0;j<n;++j){
            for(int k = 0;k<n;++k){
                cout<<s[j][k]<<' ';
            }
            cout<<endl;
        }
        cout<<endl;
    }
}

int main(void){
    Solution s;
    vector<vector<string>> result;
    result = s.solveNQueens(4);
    printChess(result);
    return 0;
}