#include <stdio.h>
#include <stlib.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if(strsSize == 1)
    {
        return *strs;
    }
    if(strsSize == 0)
    {
        char * s = (char*)malloc(sizeof(char));
        *s = '\0';
        return s;
    }
    char * returnStr = NULL;
    char ch1,ch2;
    int cur = 1, strIndex = 0;
    while(1){
        ch1 = *(*strs+strIndex);
        for(cur = 0;cur<strsSize;++cur){
            if(!*(*(strs+cur)+strIndex)){
                goto returnCode;
            }
            if(*(*(strs+cur)+strIndex) == ch1)
                continue;
            else
                goto returnCode;

        }
        ++strIndex;
    }
returnCode: returnStr = (char*)malloc((strIndex+1)*sizeof(char));
    memcpy(returnStr,*strs,strIndex);
    *(returnStr+strIndex) = '\0';
    return returnStr;
}


int main(void){
    




    return 0;
}