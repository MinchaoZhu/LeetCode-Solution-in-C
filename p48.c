#include <stdio.h>

void next(int n, int l, int * nextx, int * nexty){
     int x = *nextx,  y = *nexty;
    if(x==l){
        *nexty = n-1-l;
        *nextx = y;
    }
    else if(y==l){
        *nextx = l;
        *nexty = n-1-x;
    }
    else if(x==n-1-l){
        *nexty = l;
        *nextx = y;
    }
    else{
        *nextx = n-1-l;
        *nexty = n-1-x;
    }
}

void rotate(int matrix[][5], int matrixRowSize, int matrixColSize) {
    int n = matrixRowSize,temp1,temp2,nextx,nexty;
    for(int l = 0;l<n/2;++l){
        for(int j = l;j<n-l-1;++j){
            nextx = l;nexty = j;
            temp1 = matrix[nextx][nexty];
            for(int k = 0;k<3;++k){
                next(n,l,&nextx,&nexty);
                temp2 = matrix[nextx][nexty];
                matrix[nextx][nexty] = temp1;
                temp1 = temp2;

            }
            matrix[l][j] = temp1;

        }
    }
}


int main(void){
    int m[5][5] = {
      {1, 2, 3, 4, 5},
      {6, 7, 8, 9, 10},
      {11,12,13,14,15},
      {16,17,18,19,20},
      {21,22,23,24,25}  
    };
    rotate(m,5,5);
    for(int i = 0;i<5;++i){
        for(int j=0;j<5;++j){
            printf("%2d ", m[i][j]);
        }
        printf("\n");
    }
    return 0;
}