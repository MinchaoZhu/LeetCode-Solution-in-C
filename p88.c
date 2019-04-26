#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * compare two string
 * equal return 1
 * else return 0
 * */
bool strEqual(char *s1, char *s2, int s1Start, int s1Len, int s2Start, int s2Len){
    if(s1Len!=s2Len)return 0;
    for(int i = 0;i<s1Len;++i){
        if(*(s1+s1Start+i)!=*(s2+s2Start+i))return 0;
    }
    return 1;
}

bool match(char *s1, char *s2, int s1Start, int s1Len, int s2Start, int s2Len){
    if(strEqual(s1,s2,s1Start,s1Len,s2Start,s2Len))return 1;
    if(s1Len!=s2Len)return 0;
    for(int leftLen = 1;leftLen<s1Len;++leftLen){
        if(match(s1,s2,s1Start,leftLen,s2Start,leftLen)
            &&match(s1,s2,s1Start+leftLen,s1Len-leftLen,s2Start+leftLen,s2Len-leftLen))return 1;
        if(match(s1,s2,s1Start,leftLen,s2Start+s1Len-leftLen,leftLen)
            &&match(s1,s2,s1Start+leftLen,s1Len-leftLen,s2Start,s1Len-leftLen))return 1;
    }
    return 0;
}

bool isScramble(char * s1, char * s2){
    int s1len = strlen(s1), s2len = strlen(s2);
    return match(s1,s2,0,s1len,0,s2len);
}



int main(void){
    char* s1 = "ccabcbabcbabbbbcbb",
*s2="bbbbabccccbbbabcba";
    bool x;
    x = isScramble(s1,s2);
    printf("%d\n",x);


    return 0;
}