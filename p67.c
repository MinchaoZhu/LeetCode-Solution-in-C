#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* addBinary(char* a, char* b) {
    int la = strlen(a), lb = strlen(b);
    int lc = (la>lb?la:lb)+1;
    int carry = 0;
    char *new = (char*)malloc(sizeof(char)*(lc+1));
    new[lc] = '\0';
    while(la||lb){
        if(la)carry+=a[--la]-'0';
        if(lb)carry+=b[--lb]-'0';
        new[--lc]=(carry&1)+'0';
        carry = carry>>1;
    }
    new[0] = '1';
    if(carry){
        return new;
    }
    else
        return new+1;
}




int main(void){
    char* a = "10";
    char* b = "101";
    char* s;
    s = addBinary(a,b);
    printf("%s\n",s);

    return 0;
}