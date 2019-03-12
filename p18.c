#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void MergeSort2(int A[], int len)
{
    int len1 = 2,lenMax = 2*len;
    int A1[len];
    int *temp1, *temp2, *temp;
    int i, j, divNum = (len-1)/2+1;//i为循环变量 divNum为在这一步被分割后的数组个数
    int m,n,start;//游标
    for(i = 0;i<len;i++)
    {
        A1[i] = A[i];
    }
    temp1 = A;//根据上一次结果进行下次排序
    temp2 = A1;//用于存储上次结果的数组
    while(len1 < lenMax)
    {
        divNum = (len-1)/len1 +1;//按照divNum个数组进行合并
        for(i = 0;i<divNum-1;i++)
        {
            m = 0;n=0;
            start = i*len1;
            for(j = 0;j<len1;j++)//每一组一共需要排序len1个元素
            {//每一次取出两个数组中第一个元素中最小的那一个
                /**
                需要比较的两个数组下标分别为m 和 n+len1/2
                **/
                if(m>=len1/2)
                {
                    *(temp1+start+j) = *(temp2+start+n+len1/2);
                    n++;
                }
                else
                {
                    if(n>=len1/2)
                    {
                        *(temp1+start+j) = *(temp2+start+m);
                        m++;
                    }
                    else
                    {
                        if(*(temp2+start+m)<=*(temp2+start+n+len1/2))
                        {
                            *(temp1+start+j) = *(temp2+start+m);
                            m++;
                        }
                        else
                        {
                            *(temp1+start+j) = *(temp2+start+n+len1/2);
                            n++;
                        }
                    }
                }
            }
        }
        m = 0;n=0;
        start = i*len1;
        for(j = 0;j<(len-i*len1);j++)//每一组一共需要排序len1个元素
        {//每一次取出两个数组中第一个元素中最小的那一个
            /**
            需要比较的两个数组下标分别为m 和 n+len1/2
            **/
            if(m>=len1/2)
            {
                *(temp1+start+j) = *(temp2+start+n+len1/2);
                n++;
            }
            else
            {
                if(start+n+len1/2 >= len)
                {
                    *(temp1+start+j) = *(temp2+start+m);
                    m++;
                }
                else
                {
                    if(*(temp2+start+m)<=*(temp2+start+n+len1/2))
                    {
                        *(temp1+start+j) = *(temp2+start+m);
                        m++;
                    }
                    else
                    {
                        *(temp1+start+j) = *(temp2+start+n+len1/2);
                        n++;
                    }
                }
            }


        }
        /**
        交换两个地址,保证最后temp2是有序的那一个
        **/
        temp = temp1;
        temp1 = temp2;
        temp2 = temp;
        len1 *= 2;
    }
    for(i=0;i<len;i++)
    {
        A[i] = *(temp2+i);
    }


}


bool checkExistence(int ** returnTable, int returnSize, int x, int y, int z, int l){
    if(returnSize == 0)
        return 0;
    while(**(returnTable+returnSize-1)==x){
        if((x==*(*(returnTable+returnSize-1)+0)&&y==*(*(returnTable+returnSize-1)+1)&& z == *(*(returnTable+returnSize-1)+2)&& l==*(*(returnTable+returnSize-1)+3)))
            return 1;
        --returnSize;
        if(returnSize<1)
            return 0;
    } 
    return 0;
}
/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize) {
    if(numsSize<4)
        return NULL;
    MergeSort2(nums,numsSize);
    int cur0,cur1,first = 2,end = numsSize-1;
    int sum,reSize = 20;
    int ** returnTable = (int**)malloc(20*sizeof(int*)),**reTemp;
    int * temp;
    *returnSize = 0;
    for(cur0=0;cur0<numsSize-3;++cur0){
        for(cur1=cur0+1;cur1<numsSize-2;++cur1){
            first = cur1+1;
            end = numsSize-1;
            while(first<end){
                sum = nums[cur0]+nums[cur1]+nums[first]+nums[end];
                if(sum==target&&!checkExistence(returnTable,*returnSize,nums[cur0],nums[cur1],nums[first],nums[end])){
                    temp = (int*)malloc(4*sizeof(int));
                    *temp = nums[cur0];
                    *(temp+1) = nums[cur1];
                    *(temp+2) = nums[first];
                    *(temp+3) = nums[end];
                    if(*returnSize>=reSize){
                        reTemp = returnTable;
                        returnTable = (int**)malloc((20+reSize)*sizeof(int*));
                        memcpy(returnTable,reTemp,reSize*sizeof(int*));
                        reSize += 20;
                        free(reTemp);
                    }
                    *(returnTable+(*returnSize)) = temp; 
                    *returnSize = *returnSize + 1;
                    ++first;
                    --end;
                    if(nums[first]==nums[first-1])
                        ++first;
                    if(nums[end]==nums[end+1])
                        --end;
                }                
                else if(sum<target){
                    ++first;                    
                    if(nums[first]==nums[first-1])
                        ++first;
                }
                else{
                    --end;
                    if(nums[end]==nums[end+1])
                        --end;
                }
            }
        }
    }
    if(*returnSize == 0)   
        return NULL;

    return returnTable;

}











int main(void){
    int nums[6] = {-1,0,1,2,-1,-4};
    int target = -1;
    int **re, returnSize = 0;
    re = fourSum(nums,6,target,&returnSize);

    for(int i=0;i<returnSize;++i){
        for(int j = 0;j<4;++j){
            printf("%d ",*(*(re+i)+j));
        }
        printf("\n");
    }

    return 0;    
}