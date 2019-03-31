#include <stdio.h>




int trap(int* h, int n) {
    int high=h[0], left = 0;
    int right = 1, hightest=h[1],posOfHisghest=0;
    int i = 0;
    int S = 0;
    while(right<n){
        high = h[left];
        hightest = h[right];
        posOfHisghest = right;
        while(right<n&&h[right]<high){
            if(h[right]>hightest){
                hightest = h[right];
                posOfHisghest = right;
            }
            ++right;
        }
        if(right<n){
            for(i = left+1;i<right;++i){
                S += high-h[i];
            }
            left = right;
            ++right;
        }
        else{
            right = posOfHisghest;
            high = h[posOfHisghest];
            for(i = left+1;i<right;++i){
                S += high-h[i];
            }            
            left = right;
            ++right;
        }
    }
    return S;
}

int main(void){
    int A[12] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int S;
    S = trap(A,12);
    printf("%d\n",S);



}