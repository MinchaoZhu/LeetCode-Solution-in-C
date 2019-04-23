#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int x,y;
        vector<vector<bool>> flag(board.size(),vector<bool>(board[0].size(),0));
        for(x=0;x<board.size();++x){
            for(y=0;y<board[0].size();++y){
                if(board[x][y] == word[0]){
                    flag[x][y] = 1;
                    if(search(board,word,flag,x,y,0))
                        return 1;
                    flag[x][y] = 0;
                }
            }
        }
        return 0;
    }

private:
    bool search(vector<vector<char>>& board, string& word, vector<vector<bool>>& flag, int x, int y, int cur){
        if(cur==word.size()-1) return 1;
        
        if(x-1>=0&&board[x-1][y]==word[cur+1]&&!flag[x-1][y]){
            flag[x-1][y] = 1;
            if(search(board,word,flag,x-1,y,cur+1)) return 1;
            flag[x-1][y] = 0;
        }
        if(x+1<board.size()&&board[x+1][y]==word[cur+1]&&!flag[x+1][y]){
            flag[x+1][y] = 1;
            if(search(board,word,flag,x+1,y,cur+1)) return 1;
            flag[x+1][y] = 0;
            
        }
        if(y-1>=0&&board[x][y-1]==word[cur+1]&&!flag[x][y-1]){
            flag[x][y-1] = 1;
            if(search(board,word,flag,x,y-1,cur+1)) return 1;
            flag[x][y-1] = 0;
        }
        if(y+1<board[0].size()&&board[x][y+1]==word[cur+1]&&!flag[x][y+1]){
            flag[x][y+1] = 1;
            if(search(board,word,flag,x,y+1,cur+1)) return 1;
            flag[x][y+1] = 0;
        }
        return 0;
    }
};



int main(void){
    /**
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string words = "SEE";
    */

    vector<vector<char>> board = {{'a'}};
    string words("b");
    bool x;
    Solution s;
    x = s.exist(board,words);
    cout<<x<<endl;
    return 0;
}