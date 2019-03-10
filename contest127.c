#include <stdio.h>

void QuickSortF(int *A, int start, int end)
{
    int key = *(A+start),len = end - start +1;
    int i = start,j = end;
    int keyPos = start;
    if(start != end)
    {
        while(i!=j)
        {
            while(A[j] >= key)
            {
                j--;
                if(i==j)
                {
                    goto first;
                }
            }
            A[i] = A[j];
            A[j] = key;
            keyPos = j;
            while(A[i] <=key)
            {
                i++;
                if(i==j)
                {
                    goto first;
                }
            }
            A[j] = A[i];
            A[i] = key;
            keyPos = i;
        }
 first:
        if(keyPos > start+1)
        {
            QuickSortF(A,start,keyPos-1);
        }
        if(keyPos < end - 1)
        {
            QuickSortF(A,keyPos+1,end);
        }
    }
}

void QuickSort(int *A, int len)
{
    QuickSortF(A,0,len-1);
}


int largestSumAfterKNegations(int* A, int ASize, int K) {
    int i,temp = 0;
    QuickSort(A,ASize);
    for(i = 0;i<ASize;++i){
        if(K&&*(A+i)<=0){
            temp -= *(A+i);
            --K;
        }
        else{
            break;
        }        
    }
    if(K>0){
        K = K%2;
        if(!i){
            temp += K?-*A:*A;
            ++i;
            K = 0;
        }
        if(K){
            if(-*(A+i-1)>*(A+i)){
                temp -= *(A+i);
                ++i;
            }
            else{
                temp += 2**(A+i-1);
            }
        } 
    }
    for(;i<ASize;++i){
        temp += *(A+i);
    }
    return temp;
}



int main(void){
    int A[3] = {4,2,3};
    int ASize = 3,r;
    r = largestSumAfterKNegations(A,ASize,1);
    printf("%d\n",r);

}