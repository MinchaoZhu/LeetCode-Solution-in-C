#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>

int divide(int D, int d) {
    bool sD= 0, sd = 0;
    sD = D<0?1:0;
    sd= d<0?1:0;
    if(d==1||d==-1){
        if(D==INT_MIN&&d==-1)
            return INT_MAX;
        else if(D==INT_MIN&&d==1)
            return INT_MIN;
        else
            return sD^sd==0?abs(D):-abs(D);
    }
    else{
        if(d==INT_MIN){
            if(D==INT_MIN)
                return 1;
            else
                return 0;
        }
        if(D==INT_MIN&&abs(d)==2){
            if(sD)
                return INT_MAX>>1;
            else
                return -(INT_MAX>>1);
            
            
        }        
        if(D==INT_MIN){
            D +=1;
        }
        unsigned int i,k = 0,DD = abs(D),dd = abs(d),temp = dd,temp1,ret=0;        
        if(dd>DD)
            return 0;
        if(DD>=(INT_MAX>>1)){
            k = 31;
            temp = dd<<k;
            goto Line;
        }
        while(temp<=DD){
            if(temp<=(INT_MAX>>1)){
                temp = temp<<1;
                ++k;
                //temp = temp*2^k
            }
            else{
                break;
            }
        }
    Line:
        temp1 = 1<<(k-1);
        int res = DD;
        while(res>=dd){
            if(res>=temp){
                ret+= temp1;
                temp1 = temp1>>1;
                res -= temp;//temp = temp* 2^i
                temp = temp>>1;//temp = temp * 2^i-1
            }
            else{
                temp = temp>>1;
            }
        }
        return sD^sd==0?ret:-ret;
    }
}


int main(void){
    int D = INT_MAX, d=2,ret = 0;
    ret = divide(D,d);
    printf("%d\n",ret);

    return 0;
}