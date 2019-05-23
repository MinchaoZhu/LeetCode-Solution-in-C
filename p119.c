#include <stdlib.h>





/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize){
    int * result = (int*)malloc(sizeof(int)*(rowIndex+1));
    *returnSize = rowIndex+1;
    result[0] = 1;
    for(int i = 1;i<*returnSize;++i){
        result[i] = 1;
        for(int j = i-1;j>0;--j){
            result[j] += result[j-1];
        }
    }
    return result;
}

int main(void){
    int t;
    getRow(4,&t);

}