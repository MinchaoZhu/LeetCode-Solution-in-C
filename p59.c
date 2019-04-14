#include <stdio.h>
#include <stdlib.h>



/**
 * Return an array of arrays.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n) {
    int ** result = (int**)malloc(sizeof(int*)*n);
    int i,j,k,add = 1,subLen = n,value = 1;
    for(i = 0;i<n;++i){
        result[i] = (int*)malloc(sizeof(int)*n);
    }
    i=0;j=0;
    while(subLen>0){
        for(k = 0;k<subLen;++k){
            result[i][j] = value++;
            j+=add;
        }
        j-=add;
        i+=add;
        for(k = 0;k<subLen-1;++k){
            result[i][j] = value++;
            i+=add;
        }
        i-=add;
        j-=add;
        add*=-1;
        --subLen;
    }
    return result;
}

void printMatrix(int ** m, int size){
    for(int i = 0;i<size;++i){
        for(int j = 0;j<size;++j){
            printf("%d ",m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


int main(void){
    int ** m;
    m = generateMatrix(4);
    printMatrix(m,4);




    return 0;
}