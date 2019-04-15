#include <stdio.h>
#include <stdlib.h>



char* addBinary(char* a, char* b) {
    int carry = 0,i,j;
    int len=0,la=0,lb=0;
    char*aa=a,*bb=b;
    while(*a){
        ++la;
        ++a;
    }
    while(*b){
        ++lb;
        ++b;
    }
    len = la>lb?la:lb;
    if(la<lb){
        a=bb;
        b=aa;
        lb=la;
    }
    else{
        a = aa;
        b = bb;
    }
    aa = (char*)malloc(sizeof(char)*(len+1));
    aa[len] = '\0';
    j = len-1;
    for(i = lb-1;i>=0;--i,--j){
        aa[j] = a[j]+b[i]+carry-2*'0';
        carry = aa[j]/2;
        aa[j] = '0'+aa[j]%2;
    }
    for(;j>=0;--j){
        aa[j] = a[j]+carry-'0';
        carry = aa[j]/2;
        aa[j] = '0'+aa[j]%2;
    }
    if(!carry)return aa;
    else{
        bb = (char*)malloc(sizeof(char)*(len+2));
        bb[0] = 1+'0';
        bb[len+1] = '\0';
        for(i = 1;i<len+1;++i){
            bb[i] = aa[i-1];
        }
        return bb;
    }

}




int main(void){
    char* a = "1";
    char* b = "111";
    char* s;
    s = addBinary(a,b);
    printf("%s\n",s);

    return 0;
}