#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPalindrome();
char* longestPalindrome();


int isPalindrome(char *s, int len){
    char * head = s, * tail = s + len - 1;
    if(!len)
        return 0;
    while(head <= tail){
        if(*head == *tail){
            ++head;
            --tail;
        }
        else{
            return 0;
        }
    }
    return len;
}


char* longestPalindrome(char* s) {
    int subStrLen = 1, maxLen=0, temp;
    char * longestStr, * returnStr;
    if(!*s)
        return s;
    while(*s){
        while(*(s+subStrLen-1)){
            temp =isPalindrome(s,subStrLen);
            if(temp > maxLen){
                maxLen = subStrLen;
                longestStr = s;
            }
            ++subStrLen;
        }
        subStrLen = 1;
        ++s;
    }
    returnStr = (char*)malloc((maxLen+1)*sizeof(char));
    memcpy(returnStr,longestStr,maxLen);
    *(returnStr+maxLen) = '\0';
    return returnStr;

}

int main(void){
    char * s = "bcbd";
    printf("%s\n",longestPalindrome(s));

    return 0;
}