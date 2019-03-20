#include <stdio.h>



bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    int i,j,k,l;
    char ch1,ch2;
    for(i = 0;i<9;i++)//check every row of the board
    {
        for(j = 0;j<8;j++)
        {
            ch1 = board[i][j];
            if(ch1 == '.') continue;
            for(k = j+1;k<9;k++)
            {
                ch2 = board[i][k];
                if(ch2 == '.') continue;
                if(ch1 == ch2) return 0;
            }
        }
    }

    for(i = 0;i<9;i++)//check every col of the board
    {
        for(j = 0;j<8;j++)
        {
            ch1 = board[j][i];
            if(ch1 == '.') continue;
            for(k = j+1;k<9;k++)
            {
                ch2 = board[k][i];
                if(ch2 == '.') continue;
                if(ch1 == ch2) return 0;
            }
        }
    }

    for(int firstX = 0;firstX<7;firstX += 3)//check every 3*3 block of the board
    {
        for(int firstY = 0;firstY<7;firstY += 3)//check every 3*3 block of the board
        {
            for(i = 0;i<3;i++)//for every block, check if every different elements are equal, except '.' 
            {
                for(j = 0;j<3;j++)
                {
                    if(i==2 && j==2) continue;
                    ch1 = board[firstX+i][firstY+j];
                    if(ch1 == '.') continue;
                    if(j==2)
                    {
                        k = i+1;
                        l = 0;
                    }
                    else
                    {
                        k = i;
                        l = j+1;
                    }
                    while(k<3)
                    {
                        while(l<3)
                        {
                            ch2 = board[firstX+k][firstY+l];
                            l++;
                            if(ch2 == '.') continue;
                            if(ch1 == ch2) return 0;

                        }
                        k++;
                        l = 0;
                    }


                }
            }
        }
    }


    return 1;
}

int main(void){



    return 0;    
}