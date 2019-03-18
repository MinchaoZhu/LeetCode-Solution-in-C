#include <stdio.h>

int longestValidParentheses(char *s){
    if(!s)
        return 0;
    if(*s=='\0')
        return 0;
    char * ss = s;
    int pVal = 0, len = 0, max0 = 0,strLen = 0,i;
    while(*s){
        ++strLen;
        if(*s=='('){
            ++pVal;
            ++len;
        }
        else{
            pVal--;
            ++len;
        }
        if(pVal==0){
            max0 = len>max0?len:max0;
        }
        else if(pVal < 0){
            len = 0;
            pVal = 0;
        }
        ++s;
    }
    int max[strLen];
    for(i = 0;i<strLen;++i){
        max[i] = 0;
    }
    max[0] = max0;
    for(i = 1;i<strLen;++i){
        len = 0;
        pVal = 0;
        s = ss+i;
        if(*s==')')
            continue;
        while(*s){
            if(*s=='('){
                ++pVal;
                ++len;
            }
            else{
                pVal--;
                ++len;
            }
            if(pVal==0){
                max0 = len>max0?len:max0;
            }
            else if(pVal < 0){
                len = 0;
                pVal = 0;
            }
            ++s;
        }
    }
    for(i = 0;i<strLen;++i){
        max0 = max0>max[i]?max0:max[i];
    }
    return max0;
}


int main(void){
    char * s = "(()";
    int max = longestValidParentheses(s);

    printf("%d\n",max);


    return 0;
}
