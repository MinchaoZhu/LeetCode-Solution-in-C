#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


#define SIZE 1350

void SelectSort(int A[], int len)//参数为int型数组和数组长度len
{
    int i,j;//循环变量
    int numMin, numAi, minIndex;
    for(i=0;i<len;i++)//排序i次
    {
        numAi = A[i];
        numMin = A[i];
        minIndex = i;
        for(j=i;j<len;j++)//每一次排序,从第i个元素开始,往后遍历数组找到最小/最大的那个数,并与第i个元素交换位置
        {
            if(A[j]<numMin)
            {
                numMin = A[j];
                minIndex = j;
            }
        }
        A[i] = A[minIndex];
        A[minIndex] = numAi;
    }
}

bool checkSame(int * canCombi, int * pre, int size1, int size2){
    if(size1!=size2)
        return 0;
    for(int i = 0;i<size1;++i){
        if(canCombi[i]!=pre[i])
            return 0;
    }
    return 1;
}

bool validOut(int *** preturnCombi, int ** pcolumnSizes, int sum, int * canCombi, int size){
    int *  temp = *(*preturnCombi+sum-1);
    int len = *(*pcolumnSizes+sum-1);
    while(canCombi[0]<=temp[0]){
        if(checkSame(canCombi,temp,size,len))
            return 0;
        --sum;
        if(sum==0)
            return 1;
        temp = *(*preturnCombi+sum-1);
        len = *(*pcolumnSizes+sum-1);
    }
    return 1;
}

void search(int *** preturnCombi, int ** pcolumnSizes, int * candidates, int candidatesSize, int cur, int residue, int *returnSize, int * canCombi, int canCombiSize){
    int * new;
    int i;
    if(residue<0){
        free(canCombi);
        return;
    }
    else if(residue==0){
        if(*returnSize>0&&!validOut(preturnCombi,pcolumnSizes,*returnSize, canCombi,canCombiSize))
            return;
        *(*preturnCombi+*returnSize) = canCombi;
        *(*pcolumnSizes+*returnSize) = canCombiSize;
        *returnSize += 1;
        return;
    }
    else{
        for(i = cur;i<candidatesSize;++i){     
            new = (int*)malloc(sizeof(int)*SIZE);
            memcpy(new,canCombi,sizeof(int)*canCombiSize);
            *(new+canCombiSize) = *(candidates+i);
            search(preturnCombi,pcolumnSizes, candidates,candidatesSize,i+1,residue-*(candidates+i), returnSize, new, canCombiSize+1);
        }
        free(canCombi);
    }
}




/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combinationSum2(int* candidates, int candidatesSize, int target, int** pcolumnSizes, int* returnSize) {
    SelectSort(candidates,candidatesSize);
    int ** returnCombi = (int**)malloc(SIZE*sizeof(int*));
    *pcolumnSizes = (int*)malloc(SIZE*sizeof(int));
    *returnSize = 0;
    int * canCombi = (int*)malloc(sizeof(int)*SIZE);
    int canCombiSize = 0;
    search(&returnCombi, pcolumnSizes, candidates, candidatesSize,0, target, returnSize, canCombi, canCombiSize);
    return returnCombi;
}




int main(void){
    int ca[65] = {32,10,32,5,25,9,18,23,28,24,10,33,6,24,32,18,10,28,17,18,13,22,7,25,22,17,28,13,17,32,19,6,7,17,7,28,21,12,8,6,31,13,34,24,24,31,8,29,16,20,12,25,29,6,15,16,19,30,17,23,27,31,17,29};
    int target = 28;
    //int ca[2] = {1,2};
    int ** re,reSize,*columnSizes;
    re = combinationSum2(ca,65,target,&columnSizes,&reSize);
    int i,j; 
    for(i = 0;i<reSize;++i){
        for(j = 0;j<*(columnSizes+i);++j){
            printf("%d ",*(*(re+i)+j));
        }
        printf("\n");
    }
    return 0;
}