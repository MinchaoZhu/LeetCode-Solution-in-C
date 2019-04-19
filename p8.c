#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>

bool validIntPlus(int num1, int num2){
    if(num2<0){
        if(num1>INT_MIN/10)return 1;   
        else if(num1<INT_MIN/10)return 0;
        else{
            if(num2==-9)return 0;
            else return 1;
        }
    }
    else if(num2>0){
        if(num1<INT_MAX/10)return 1;
        else if(num1>INT_MAX/10)return 0;
        else{
            if(num2>=8)return 0;
            else return 1;
        }
    }
    else{
        if(abs(num1)>INT_MAX/10)return 0;
        else return 1;
    }
}

int myAtoi(char* str) {
    while(*str&&*str==' ')++str;
    int result = 0;
    if(!*str)return 0;
    if(!(*str=='-'||*str=='+'||*str>='0'&&*str<='9'))
        return 0;
    bool sign = 0;//0 means positive, 1 means negative
    if(*str=='-'){
        sign = 1;
        ++str;
    }
    else if(*str=='+'){
        ++str;
    }
    while(*str&&*str=='0')++str;
    if(sign){//negative
        while(*str&&*str>='0'&&*str<='9'){
            if(validIntPlus(result,-1*(*str-'0'))){
                result *= 10;
                result += -1*(*str-'0');
            }
            else return INT_MIN;
            ++str;
        }
    }
    else{//positive
        while(*str&&*str>='0'&&*str<='9'){
            if(validIntPlus(result,*str-'0')){
                result *= 10;
                result += *str-'0';
            }
            else return INT_MAX;
            ++str;
        }
    }
    return result;
}




int main(void){
    
    char* s = "  0000000000012345678";
    int i;
    i = myAtoi(s);
    printf("%d\n",i);
    
   /*
   int a,b;
   a = 214748364;
   b = 0;
   printf("%d\n",validIntPlus(a,b));
    */
    return 0;
}