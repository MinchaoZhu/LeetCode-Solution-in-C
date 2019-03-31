#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(char* c, int len){
    char temp;
    for(int i = 0;i<len/2;++i){
        temp = *(c+i);
        *(c+i) = *(c+len-1-i);
        *(c+len-1-i) = temp;
    }
}


int plus(char *result,char*s1,char*s2){
    char*temp;
    int lenTemp;
    int len1 = 0,len2 = 0;
    while(*(s1+len1)){
        ++len1;
    }
    while(*(s2+len2)){
        ++len2;
    }
    if(len2<len1){//let len1 < len2
        temp = s1;
        s1 = s2;
        s2 = temp;
        lenTemp = len1;
        len1 = len2;
        len2 = lenTemp;
    }
    if(len1==0){
        memcpy(result,s2,len2*(sizeof(char)));
        *(result+len2) = '\0';
        return len2;
    }
    int p, res = 0, newAdd, i;
    for(i = 0;i<len1;++i){
        p = res + *(s1+i) + *(s2+i) - 96;
        res = p/10;
        newAdd = p%10;
        *(result+i) = newAdd+48;
    }
    for(i = len1;i<len2;++i){
        p = res + *(s2+i)-48;
        res = p/10;
        newAdd = p%10;
        *(result+i) = newAdd+48;
    }
    if(res!=0){
        *(result+i) = '1';
        ++i;
    }
    *(result+i) = '\0';
    return i;
}

void mulDigit(char * result, char * num, int numLen, char digit, int exp){
    int mul, res = 0, newAdd;
    int i = 0,j = 0;
    for(j = 0;j<exp;++j){
        *(result+j) = 48;
    }
    for(;i<numLen;++i){
        mul = (digit-48)*(*(num+i)-48);
        mul += res;
        newAdd = mul%10;
        *(result+i+j) = newAdd+48;
        res = mul/10;
    }
    if(res!=0){
        *(result+i+j) = res+48;
        ++i;
    }
    *(result+i+j) = '\0';
}

char* multiply(char* num1, char* num2) {
    int len1 = 0, len2 = 0,lenTemp,i,newLen, len = 0;
    char *temp;
    if(*num1==48||*num2==48){
        char* ret = (char*)malloc(sizeof(char)*2);
        *ret = 48;
        *(ret+1)='\0';
        return ret;
    }
    while(*(num1+len1)){
        ++len1;
    }
    while(*(num2+len2)){
        ++len2;
    }
    if(len2<len1){//let len1 < len2
        temp = num1;
        num1 = num2;
        num2 = temp;
        lenTemp = len1;
        len1 = len2;
        len2 = lenTemp;
    }
    newLen = len1+len2+2;
    char * ret = (char*)malloc(sizeof(char)*newLen);
    char * ca[len1];
    for(i = 0;i<len1;++i){
        ca[i]  = (char*)malloc(sizeof(char)*newLen);
    }
    char * num1Temp = (char*)malloc(sizeof(char)*newLen);
    memcpy(num1Temp,num1,len1+1);
    char * num2Temp = (char*)malloc(sizeof(char)*newLen);
    memcpy(num2Temp,num2,len2+1);
    reverse(num1Temp,len1);
    reverse(num2Temp,len2);
    for(i = 0;i<len1;++i){
        mulDigit(ca[i],num2Temp,len2,*(num1Temp+i),i);
    }
    memcpy(ret,ca[0],newLen);    
    while(*(ret+len)){
        ++len;
    }
    for(i = 1;i<len1;++i){
        len = plus(ret,ca[i],ca[0]);
        memcpy(ca[0],ret,len+1);
    }
    reverse(ret,len);
    return ret;
}

int main(void){
    char* num1 = "123";
    char* num2 = "456";
    char* new;
    new  = multiply(num1,num2);
    printf("%s\n",new);
    return 0;
}