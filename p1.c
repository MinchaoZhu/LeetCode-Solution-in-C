/*
 * @Author: Minchao Zhu 
 * @Date: 2019-03-02 23:33:28 
 * @Last Modified by: Minchao Zhu
 * @Last Modified time: 2019-03-02 23:36:38
 */



/**Problem 1: Two Sum
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include<math.h>

typedef struct hashTableNode{
    int value; //the number value in nums
    int address; //the address of number in nums
    unsigned char status; // 0 means It isn't occupied, 1 means it is occupied, 2 means it used to be occupied but now the data is deleted.
}hashNode;



hashNode * hashTable(int size){
    int i = 0;
    hashNode * hashTable = (hashNode*) malloc(3*size*sizeof(hashNode)); // create the hashtable with 3*numsSize valid space
    for(;i<3*size;++i)
    {
        (hashTable+i)->status = 0;
    }
    return hashTable;
}
int hashFunction(int number, int tableSize){
    int hashValue = number%tableSize; // directly mod the number value
    return abs(hashValue); // Regarding the negative value of number, the hashFunction treat it the same as positive
}
int hashInsert(hashNode* hTable, int number, int address, int tableSize){
    int insertPosition = hashFunction(number,tableSize);
    int i = 0;
    while((hTable+insertPosition)->status==1) // this loop finds the first blank position in HashTable forward from the original hashValue 
    {
        ++i;
        insertPosition = hashFunction(number+i, tableSize);
		if(i >= tableSize-1)
			return 0; // failing to insert
    }
    (hTable+insertPosition)->value = number;
    (hTable+insertPosition)->address = address;
    (hTable+insertPosition)->status = 1;
    return 1;//inter successfully
}

int hashFind(hashNode* hTable, int number, int tableSize){
    int count = 0, hashPosition = hashFunction(number,tableSize);
    while((hTable+hashPosition)->status != 0) // search the number until the status is 0 or whole table was searched, failed to find.
																	   // search the number until find the number and status is not 2, successfully find.
    {
        if((hTable+hashPosition)->value == number)
		{
			if((hTable+hashPosition)->status == 1) // or unequal to 2
				return (hTable+hashPosition)->address;
        }
        else
        {
            ++count;
            hashPosition = hashFunction(number+count,tableSize); // next position is add 1. 
            if(count == tableSize - 1)
                return -1;
        }
    }
    return -1;
}

int* twoSum(int* nums, int numsSize, int target) {
    int * result = (int*)malloc(2*sizeof(int));
    int cur = 0,hashValue,anotherNum,anotherNumPosition;
    hashNode * hTable = hashTable(numsSize);
    for(cur = 0;cur < numsSize;cur++)
    {
        hashInsert(hTable,*(nums+cur),cur,3*numsSize);
        anotherNum = target - *(nums+cur);
        anotherNumPosition = hashFind(hTable,anotherNum,3*numsSize);
        if(anotherNumPosition != -1 && anotherNumPosition != cur)
        {
            *result = anotherNumPosition;
            *(result+1) = cur;
            break;
        }
    }
    free(hTable);

    return result;
}

int main(void){
    int * result, nums[3] = {3, 2, 4};
    int target = 6, numsSize = 3;
    result = twoSum(nums,numsSize,target);

    printf("%d %d\n", *result, *(result+1));
    return 0;
}
