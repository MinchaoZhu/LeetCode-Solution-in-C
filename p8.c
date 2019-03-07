#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int myAtoi(char* str) {
    int returnNum = 0, count = 0;
    bool sign = 0;
    if(*str == 45||*str == 43||(*str>47&&*str<58)||*str == 32){
        while(*str==32){
            ++str;
        }
        if(*str == 45||*str == 43||(*str>47&&*str<58))
        {
            if(!*str)
                return 0;
            if(*str == 45){
                sign = 1;
                ++str;
                if(!(*str>47&&*str<58)||!*str)  
                    return 0;
            }
            else if(*str == 43){
                ++str;
                if(!(*str>47&&*str<58)||!*str)  
                    return 0;            
            }
            while(*str&&count<9){
                returnNum *= 10;
                returnNum += *str - 48;
                ++count;
                ++str;
                if(!(*str>47&&*str<58)||!*str)   
                    return sign?-1*returnNum:returnNum;// if the number ends when count is less than 10, output the number.];
            }
            if(*(str+1))
                return 0;
            if(!sign){//positive number
                if(returnNum < INT_MAX/10)
                    return returnNum*10+(*str-48);
                else if(returnNum == INT_MAX/10)
                    return (*str-48)>7?0:returnNum*10+(*str-48);
                else
                    return 0;
            }
            else{//negtive number
                if(-1*returnNum > INT_MIN/10)
                    return -1*(returnNum*10+(*str-48));
                else if(-1*returnNum == INT_MIN/10)
                    return (*str-48)==9?0:-1*(returnNum*10+(*str-48));
                else
                    return 0;
            }
        }
    }
    else
        return 0;
    return 0;
}




int main(void){
    char* s = "2147483647";
    int i;
    i = myAtoi(s);
    printf("%d\n",i);


    return 0;
}