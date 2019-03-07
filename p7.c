#include <stdio.h>
#include <limits.h>
int reverse(int x) {
    int temp = 0,temp1 = 0; 
    while(x/10){
        temp *= 10;
        temp += x%10;
        x /= 10;
    }
    x = x%10;
    if(temp>0){
        if(temp < INT_MAX/10){
            return 10*temp+x;
        }
        else if(temp>INT_MAX/10)
            return 0;
        else{
            if(x>7)
                return 0;
            else
                return 10*temp+x;
            }
    }
    else{
        if(temp > INT_MIN/10){
                    return 10*temp+x;
                }
                else if(temp<INT_MIN/10)
                    return 0;
                else{
                    if(x<-8)
                        return 0;
                    else
                        return 10*temp+x;
                    }
    }
}



int main(void){
    int x = -123;
    printf("%d\n",reverse(x));

    return 0;
}