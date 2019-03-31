#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


void search(int *** preturnCombi, int ** pcolumnSizes, int * candidates, int candidatesSize, int cur, int residue, int *returnSize, int capacity, int * canCombi, int canCombiSize, int canCombiCapacity){
    int * new, **temp,*temp1,*temp2,**temp0;
    int i;
    if(residue<0){
        free(canCombi);
        return;
    }
    else if(residue==0){
        if(*returnSize>=capacity){
            temp = (int**)malloc(sizeof(int*)*(capacity+10));
            temp0 = *preturnCombi;
            memcpy(temp,*preturnCombi,sizeof(int*)*capacity);
            *preturnCombi = temp;   
            free(temp0);         
            temp1 = (int*)malloc(sizeof(int)*(capacity+10));
            memcpy(temp1,*pcolumnSizes,sizeof(int)*capacity);
            temp2 = *pcolumnSizes;
            *pcolumnSizes = temp1;
            free(temp2);
            capacity += 10;
        }
        *(*preturnCombi+*returnSize) = canCombi;
        *(*pcolumnSizes+*returnSize) = canCombiSize;
        *returnSize += 1;
        return;
    }
    else{
        for(i = cur;i<candidatesSize;++i){            
            if(canCombiSize>=canCombiCapacity){
                temp1 = (int*)malloc(sizeof(int)*(2*canCombiCapacity));
                memcpy(temp1,canCombi,sizeof(int)*canCombiSize);
                temp2 = canCombi;
                free(temp2);
                canCombi = temp1;
                new = (int*)malloc(sizeof(int)*(2*canCombiCapacity));
                canCombiCapacity *= 2;
            }            
            else{
                new = (int*)malloc(sizeof(int)*canCombiCapacity);
            }
            memcpy(new,canCombi,sizeof(int)*canCombiSize);


            *(new+canCombiSize) = *(candidates+i);
            search(preturnCombi,pcolumnSizes, candidates,candidatesSize,i,residue-*(candidates+i), returnSize, capacity, new, canCombiSize+1,canCombiCapacity);
        }
        free(canCombi);
    }
}




/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combinationSum(int* candidates, int candidatesSize, int target, int** pcolumnSizes, int* returnSize) {
    int ** returnCombi = (int**)malloc(10000*sizeof(int*));
    *pcolumnSizes = (int*)malloc(10000*sizeof(int));
    *returnSize = 0;
    int * canCombi = (int*)malloc(sizeof(int)*10000);
    int canCombiSize = 0;
    int canCombiCapacity = 10000;
    search(&returnCombi, pcolumnSizes, candidates, candidatesSize, 0, target, returnSize, 10000, canCombi, canCombiSize, canCombiCapacity);
    return returnCombi;
}



int main(void){
    int ca[7] = {5,10,8,4,3,12,9};
    int target = 27;
    //int ca[2] = {1,2};
    int ** re,reSize,*columnSizes;
    re = combinationSum(ca,7,target,&columnSizes,&reSize);
    int i,j;
    for(i = 0;i<reSize;++i){
        for(j = 0;j<*(columnSizes+i);++j){
            printf("%d ",*(*(re+i)+j));
        }
        printf("\n");
    }
    return 0;
}