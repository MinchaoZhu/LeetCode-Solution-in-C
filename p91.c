#include <stdio.h>
#include <string.h>

int numDecodings(char * s){
    int len = strlen(s);
    int count[len];
    int i = len-3;
    count[len-1] = s[len-1]=='0'?0:1;
    if(len>1){
        if(s[len-2]=='1'||(s[len-2]=='2'&&s[len-1]<='6'))count[len-2] = 1+count[len-1];
        else if(s[len-2] == '0')count[len-2] = 0;
        else count[len-2] = count[len-1];
    }
    for(;i>=0;--i){
        if(s[i]=='1'||(s[i]=='2'&&s[i+1]<='6'))count[i] = count[i+1]+count[i+2];
        else if(s[i] == '0')count[i] = 0;
        else count[i] = count[i+1];        
    }
    return count[0];
}

int main(void){
    char * s = "130";
    int t;
    t = numDecodings(s);
    printf("%d\n",t);
    return 0;
}