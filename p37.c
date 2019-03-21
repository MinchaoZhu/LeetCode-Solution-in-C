#include <stdio.h>
#include <stdbool.h>
#define ROW 9
#define COL 9


bool validVal(char board[9][9], int x, int y, char val){
    int rx = x/3, ry = y/3;
    for(int i = 0;i<ROW;++i){
        if(board[x][i]==val)
            return 0;
    }
    for(int i = 0;i<COL;++i){
        if(board[i][y]==val)
            return 0;
    }
    for(int i = 0;i<3;++i){
        for(int j = 0;j<3;++j){
            if(board[rx*3+i][ry*3+j]==val)
                return 0;            
        }
    }
    return 1;

}

int nextEmpty(char board[9][9],int *px, int * py){
    for(int i = 0;i<ROW;++i){
        for(int j = 0;j<COL;++j){
            if(board[i][j] == '.'){
                *px = i;
                *py = j;
                return 1;
            }
        }
    }
    return 0;
}

bool solve(char board[9][9]){
    int x,y;
    bool flag = 1;
    char val = '1';
    if(!nextEmpty(board,&x,&y))
        return 1;
    for(;val<='9';++val){
        if(!validVal(board,x,y,val))
            continue;
        else{
            board[x][y] = val;
        }
        flag = solve(board);
        if(flag==1)
            return 1;
        else{
            board[x][y] = '.';
            continue;
        }
    }
    return 0;
}

void solveSudoku(char board[9][9]) {
    //*boardColSizes = 9;
    solve(board);
}

void print(char board[9][9]){
    int i,j;
    for(i = 0;i<9;++i){
        for(j = 0;j<9;++j){
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main(void){
    char board[9][9] = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'},
    };
    
    //print(board);
    solveSudoku(board);
    print(board);
    return 0;
}