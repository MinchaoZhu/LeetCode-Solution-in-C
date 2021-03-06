#include <stdio.h>
#include <limits.h>




int maxSumTwoNoOverlap(int* A, int ASize, int L, int M) {
    int max = INT_MIN;
    int K = ASize-L-M;
    int i = 0,gap,k,j;
    int sum = 0,temp,temp0;
    for(i = 0;i<L+M;++i){
        sum+=A[i];
    }
    temp = sum;
    temp0 = temp;
    max = max>sum?max:sum;
    for(k = 1;k<K+1;++k){
        sum-=A[k-1];
        sum+=A[L+k-1];
        sum-=A[L+k-1];
        sum+=A[L+M+k-1];
        max = max>sum?max:sum;
    }
    for(gap = 1;gap<ASize-L-M+1;++gap){
        sum=temp;
        sum-=A[L+gap-1];
        sum+=A[L+gap+M-1];
        max = max>sum?max:sum;
        temp = sum;
        for(k=1;k<K-gap+1;++k){
            sum-=A[k-1];
            sum+=A[L+k-1];
            sum-=A[L+k-1+gap];
            sum+=A[L+M+k+gap-1];
            max = max>sum?max:sum;
        }
    }
    if(L!=M){
        temp = temp0;
        for(gap = 1;gap<ASize-L-M+1;++gap){
            sum=temp;
            sum-=A[M+gap-1];
            sum+=A[M+gap+L-1];
            max = max>sum?max:sum;
            temp=sum;
            for(k=1;k<K-gap+1;++k){
                sum-=A[k-1];
                sum+=A[M+k-1];
                sum-=A[M+k+gap-1];
                sum+=A[L+M+k+gap-1];
                max = max>sum?max:sum;
            }
        }
    }
    return max;

}



int main(void){
    int A[5] = {4,6,5,2,4};
    int max;
    max = maxSumTwoNoOverlap(A,5,1,2);
    printf("%d\n",max);


    return 0;
}