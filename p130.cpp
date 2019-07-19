#include <vector>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int X = board.size();
        if(X!=0){
            int Y = board[0].size(); 
            for(int i = 0;i<X;++i){
                if(board[i][0]=='O')DFS(board,i,0);
                if(board[i][Y-1]=='O')DFS(board,i,Y-1);
            }
            for(int j = 0;j<Y;++j){
                if(board[0][j]=='O')DFS(board,0,j);
                if(board[X-1][j]=='O')DFS(board,X-1,j);
            }
            for(int i = 0;i<X;++i){
                for(int j = 0;j<Y;++j){
                    if(board[i][j]=='T')board[i][j] = 'O';
                    else board[i][j] = 'X';
                }
            }
        }
    }
private:
    void DFS(vector<vector<char>>& board, int i, int j){
        int X = board.size(),Y = board[0].size() ;
        board[i][j] = 'T';
        if(i+1<X&&board[i+1][j]=='O') DFS(board,i+1,j);
        if(i-1>=0&&board[i-1][j]=='O') DFS(board,i-1,j);
        if(j+1<Y&&board[i][j+1]=='O') DFS(board,i,j+1);
        if(j-1>=0&&board[i][j-1]=='O') DFS(board,i,j-1);
    }
};