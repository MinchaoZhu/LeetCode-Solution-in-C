#include <stdio.h>
#include <string.h>

int count(char * s, int start, int len){
    if(len<=1)return s[start]=='0'?0:1;
    else{
        if(s[start]=='0')return 0;
        if((s[start]=='1'||s[start]=='2')&&(len>1&&s[start+1]=='0')) return count(s,start+2,len-2);
        if(s[start]=='2'&&s[start+1]>'6'||s[start]>'2')return count(s,start+1,len-1);
        else return count(s,start+1,len-1)+count(s,start+2,len-2);
    }
}

int numDecodings(char * s){
    int i = 0;
    for(;i<strlen(s);++i){
        if(s[i]=='0'&&(i==0||(i>0&&s[i-1]>'2')||(i>0&&s[i-1]=='0'))) return 0;
    }
    return count(s,0,strlen(s));
}




int main(void){
    char * s = "110";
    int t;
    t = numDecodings(s);
    printf("%d\n",t);
    return 0;
}