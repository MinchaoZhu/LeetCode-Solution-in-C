#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

long ABS(long x){
    if(x<0)
        return -x;
    else 
        return x;
}


int divide(int DD, int dd) {
    long D = DD,d = dd;
    bool sD= 0, sd = 0;
    sD = D<0?1:0;
    sd= d<0?1:0;
    if(d==1||d==-1){
        if(D==INT_MIN&&d==-1)
            return INT_MAX;
        else if(D==INT_MIN&&d==1)
            return INT_MIN;
        else
            return sD^sd==0?ABS(D):-ABS(D);
    }
    else{
        if(d==INT_MIN){
            if(D==INT_MIN)
                return 1;
            else
                return 0;
        }
        D = ABS(D),d = ABS(d);   
        unsigned int i,k = 0;
        long temp = d,temp1,ret=0;   
        if(d>D)
            return 0;
        while(temp<=D){
            if(temp<=D){
                temp = temp<<1;
                ++k;
                //temp = temp*2^k
            }
            else{
                break;
            }
        }
        temp1 = 1<<(k-1);
        temp = temp>>1;
        long res = D;
        while(res>=d){
            if(res>=temp){
                ret+= temp1;
                temp1 = temp1>>1;
                res -= temp;//temp = temp* 2^i
                temp = temp>>1;//temp = temp * 2^i-1
            }
            else{
                temp = temp>>1;
                temp1 = temp1>>1;
            }
        }
        return sD^sd==0?ret:-ret;
    }
}


int main(void){
    int D = INT_MIN, d=-1,ret = 0;
    ret = divide(D,d);
    printf("%d\n",ret);

    return 0;
}