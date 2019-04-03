#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {
    int size = matrixColSize*matrixRowSize, i = 0;
    int * result = (int*)malloc(size*sizeof(int));
    int row = 0, col = 0, incre=1,j = 0;
    int rowSize = matrixRowSize, colSize = matrixColSize;
    while(i<size){
        for(j = 0;j<colSize;++j){
            result[i++] = matrix[row][col];
            col+=incre;
        }
        col-=incre;
        row+=incre;
        for(j = 0;j<rowSize-1;++j){
            result[i++] = matrix[row][col];
            row+=incre;
        }
        row-=incre;
        col-=incre;
        --rowSize;
        --colSize;
        incre = -incre;
    }
    return result;
}

int main(void){
    int ** m;
    m = malloc(3*sizeof(int*));
    int j = 0,k=0;
    for(int i = 0;i<3;++i){
        m[i] = (int*)malloc(5*sizeof(int));
        for(j = 0;j<5;++j){
            m[i][j] = ++k;
        }
    }
    int * re;
    re = spiralOrder(m,3,5);
    for(int i = 0;i<15;++i){
        printf("%d ",re[i]);
    }
    printf("\n");


    return 0;
}