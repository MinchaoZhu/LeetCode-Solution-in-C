#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>

int reverse(int x) {
    unsigned numTable[11];
    int digitSize = 0,i;
    long returnNum = 0;
    if(x > 0)
        numTable[10] = 0;
    else if(x < 0)
        numTable[10] = 1;
    else  
        return 0;
    while(x){
        numTable[digitSize] = abs(x%10);
        x/=10;
        ++digitSize;
    }
    for(i = digitSize-1;i>-1;--i){
        returnNum += numTable[digitSize - i - 1]*pow(10,i);
    }
    if(!numTable[10]){
        if(returnNum > INT_MAX)
            return 0;
        else return returnNum;
    }
    else{
        if(-1*returnNum < INT_MIN)
            return 0;
        else return -1*returnNum;
    }
}



int main(void){
    int x = -123;
    printf("%d\n",reverse(x));

    return 0;
}