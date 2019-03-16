/*
https://leetcode.com/problems/3sum-closest/

Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example:

Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/
#include <stdio.h>
#include <stdlib.h>

void MergeSort2(int A[], int len)//归并迭代
{
    int len1 = 2,lenMax = 2*len;
    int *A1 = (int*)malloc(len*sizeof(int)), *A2;
	A2 = A1;
    int *temp1, *temp2, *temp;
    int i, j, divNum = (len-1)/2+1;//i为循环变量 divNum为在这一步被分割后的数组个数
    int m,n,start;//游标

    for(i = 0;i<len;i++)
    {
        *(A1+i) = A[i];
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
	free(A2);

}

int threeSumClosest(int* nums, int numsSize, int target) {
    int closetNum = *nums+*(nums+1)+*(nums+numsSize-1),i = 0, first = 1,second = numsSize-1;
    int preDeviation,newDeviation,temp = 1<<30,temp2 = 1<<30;
    MergeSort2(nums,numsSize);
    if(target<=(*nums)*3)
        return *nums+*(nums+1)+*(nums+2);
    else if(target >= (*(nums+numsSize-1))*3)
        return *(nums+numsSize-3)+*(nums+numsSize-2)+*(nums+numsSize-1);
    for(i = 0;i<numsSize-2;++i){
        first = i+1;
        second = numsSize - 1;
        while(first<second){
            temp2 = 1<<30;
            temp = *(nums+i) + *(nums+first) + *(nums+second);
            if(temp-target == 0)
                return target;
            else if(abs(temp-target)<abs(closetNum-target)){
                closetNum = temp;
            }
            if(abs(temp-target)>abs(temp2-target))
                break;
            temp2 = temp;
            if(temp>target){
                --second;
            }
            else
            {
                ++first;
            }
            
        }
    }
    return closetNum;
}

int main(void){
    int arr[8] = {1,2,4,8,16,32,64,128};
    int target = 82;
    int c;
    c = threeSumClosest(arr,8,target);
    printf("%d\n",c);
    return 0;
}