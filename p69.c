#include <stdio.h>

int mySqrt(int n) {
    int end = 46341;
    int begin = 0;
    int mid = (end+begin)/2;
    while(end-begin>1){
        if(mid*mid>n){
            end = mid;
            mid = (begin+end)/2;
        }
        else if(mid*mid<n){
            begin = mid;
            mid = (begin+end)/2;
        }
        else return mid;
    }
    return begin;
}

int main(void){
    int n = 2147395599;
    int sq;
    sq = mySqrt(n);
    printf("%d\n",sq);

    return 0;
}