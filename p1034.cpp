#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        
        vector<int> xx;
        vector<vector<int>> yy(grid);
        int origin = grid[r0][c0];
        if(origin==color)return grid;
        check(grid,yy,xx,r0,c0,color);
        for(int i = 0;i<xx.size();i+=2){
            grid[xx[i]][xx[i+1]] = origin;
        }

        return grid;
    }

private:
    void check(vector<vector<int>>& grid,vector<vector<int>>& yy, vector<int>& xx,int x,int y,int color){
        int origin = grid[x][y];
        if(x==0||y==0||x==(grid.size()-1)||y==(grid[0].size()-1))
            grid[x][y] = color;
        else if(!(grid[x-1][y]==origin&&grid[x+1][y]==origin&&grid[x][y-1]==origin&&grid[x][y+1]==origin)){
            grid[x][y] = color;
        }
        if(x==0||y==0||x==(grid.size()-1)||y==(grid[0].size()-1));
        else if(yy[x-1][y]==origin&&yy[x+1][y]==origin&&yy[x][y-1]==origin&&yy[x][y+1]==origin){
            xx.push_back(x);
            xx.push_back(y);
        }

        if(x>0&&grid[x-1][y] == origin)check(grid,yy,xx,x-1,y,color);
        if(x<grid.size()-1&&grid[x+1][y] == origin)check(grid,yy,xx,x+1,y,color);
        if(y>0&&grid[x][y-1] == origin)check(grid,yy,xx,x,y-1,color);
        if(y<grid[0].size()-1&&grid[x][y+1] == origin)check(grid,yy,xx,x,y+1,color);
    }
};



int main(void){
    vector<vector<int>> grid = {{1,2,1,2,1,2},{2,2,2,2,1,2},{1,2,2,2,1,2}};
    vector<vector<int>> re;
    Solution s;    
    
    for(int i=0;i<grid.size();++i){
        for(int j=0;j<grid[0].size();++j){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    re = s.colorBorder(grid,1,3,1);
    for(int i=0;i<grid.size();++i){
        for(int j=0;j<grid[0].size();++j){
            cout<<re[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}