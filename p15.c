#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct hashTable{
    int value;
    unsigned char mOne; //no existence 0, and then means mOne of existence
    struct hashTable* next;
} *hashTable, hashTableNode;


hashTable initHashTable(int numsSize){
    hashTable returnTable = (hashTable)malloc(numsSize*sizeof(hashTableNode));
    for(int i = 0;i<numsSize;++i){
        returnTable[i].value = 0;
        returnTable[i].mOne = 0;
        returnTable[i].next = NULL;
    }
    return returnTable;
}


void insertHashTable(hashTable table, int value, int numsSize){
    int index = abs(value%numsSize);
    hashTable temp = table+index,pre = temp;

    if(!temp -> mOne){
        temp -> value = value;
        temp -> mOne = 1;
        return;
    }

    while(temp&&temp->mOne&&temp->value != value){
        pre = temp;
        temp = temp -> next;
    }
    if(!temp){
        temp = (hashTable)malloc(sizeof(hashTableNode));
        temp -> value = value;
        temp -> mOne = 0;
        temp -> next = NULL;
        pre -> next = temp;
    }
    else if(temp->value == value){
        temp -> mOne = temp -> mOne + 1;
    }
    return;
}

int findHashTable(hashTable table,int value, int numsSize){
    int index = abs(value%numsSize);
    hashTable temp = table+index;
    if(!temp -> mOne)
        return 0;
    while(temp){
        if(temp->value == value)
            return temp->mOne;
        temp = temp->next;
    }
    return 0;
}



int ** threeSum(int* nums, int numsSize, int* returnSize){
    int i=0,j=1,z=0,nx,ny,nz,x,y,reSize = 10;
    int ** returnTable = (int**)malloc(10*sizeof(int*)),**reTemp;
    int * temp;
    hashTable table = initHashTable(numsSize);
    *returnSize = 0;
    for(i = 0;i<numsSize;++i){
        insertHashTable(table,nums[i],numsSize);
    }
    for(i = 0;i<numsSize -3;++i){
        for(j = i+1;j<numsSize-2;++j){
            x = nums[i];
            nx = findHashTable(table,x,numsSize);
            y = nums[j];
            ny = findHashTable(table,y,numsSize);
            z = -x-y;
            nz = findHashTable(table,z,numsSize);
            if(x == y&&y == z){
                if(nx>2){
                    temp = (int*)malloc(3*sizeof(int));
                    *temp = x;
                    *temp = y;
                    *temp = z;
                    if(!*returnSize<reSize){
                        reTemp = returnTable;
                        returnTable = (int**)malloc((10+reSize)*sizeof(int*));
                        memcpy(returnTable,reTemp,reSize);
                        reSize += 10;
                        free(reTemp);
                    }
                    *(returnTable+*returnSize) = temp; 
                    *returnSize = *returnSize + 1;
                }
            }
            else
            {
                if(x == y){
                    --nx;
                    --ny;
                }
                if(y == z){
                    --ny;
                    --nz;
                }
                if(z == x){
                    --nz;
                    --nx;
                }
            }
            if(nx&&ny&&nz){
                    temp = (int*)malloc(3*sizeof(int));
                    *temp = x;
                    *temp = y;
                    *temp = z;
                    if(!*returnSize<reSize){
                        reTemp = returnTable;
                        returnTable = (int**)malloc((10+reSize)*sizeof(int*));
                        memcpy(returnTable,reTemp,reSize);
                        reSize += 10;
                        free(reTemp);
                    }
                    *(returnTable+*returnSize) = temp; 
                    *returnSize = *returnSize + 1;
            }
        }
    }
    return returnTable;
}

int main(void){
    int nums[6] = {-1, 0, 1, 2, -1, -4};
    int ** cc, returnSize = 0;
    cc = threeSum(nums,6,&returnSize);
    for(int i = 0;i<returnSize;++i){
        for(int j = 0;j<3;++j){

            printf("%d ",*(*(cc+i)+j));
        }
        printf("\n");

    }

    return 0;
}