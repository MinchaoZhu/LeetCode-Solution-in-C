#include <stdio.h>
#include <stdlib.h>





char* countAndSay(int n) {
    char * retTable[n],*pre = NULL,*now;
    char digit;
    int count,pos;
    for(int i = 0;i<n;++i){
        retTable[i] = (char*)malloc(4463*sizeof(char));
    }
    now = retTable[0];
    *now = '1';
    *(now+1) = '\0';
    for(int i = 1;i<n;++i){
        pos = 0;\
        pre = now;
        now = retTable[i];
        while(*pre){
            digit = *pre;
            count = 1;
            ++pre;
            while(*pre&&*pre==digit){
                ++count;
                ++pre;
            }
            *(now+(pos++)) = count+48;
            *(now+(pos++)) = digit;
        }
        *(now+pos) = '\0';
    }
    return now;
}



int main(void){
    int i;
    char *s;
    s = countAndSay(30);
    printf("%s\n",s);

    return 0;
}