#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

void loopFun(char** returnStr,int level, int digitsLen, int startIndex){
    char newStart;
    int i;
    switch(*(digits+level)){
        case '7': 
            loopTime = 4;
            newStart = 97+3*5;
            break;
        case '8':
            loopTime = 3;
            newStart = 97+3*6+1;
            break;
        case '9':
            loopTime = 4;
            newStart = 97 + 3*7 + 1;
            break;
        default:
            loopTime = 3;
            newStart = 97+ (*digits-50)*3;
    }
    if(level == 0){
        for(int k = 0;k<digitsLen;++k){
            *(*(returnStr+startIndex)+k) = 

        }

    }
}

void loop(char ** returnStr, int size, char * digits){
    int index;
    int loopTime,start;
    switch(*digits){
    case '7': 
        loopTime = 4;
        start = 97+3*5;
        break;
    case '8':
        loopTime = 3;
        start = 97+3*6+1;
        break;
    case '9':
        loopTime = 4;
        start = 97 + 3*7 + 1;
        break;
    default:
        loopTime = 3;
        start = 97+ (*digits-50)*3;
    }
    index = 0;
    loopFun(returnStr,loopTime,start,0,digits,size,index);
}

char** letterCombinations(char* digits, int* returnSize) {
    char * s = digits, *singleStr;
    int i = 0,j, loopTime,start,index = 0;
    *returnSize = 1;
    int len = 0;
    while(*s){
        if(*s == '7'|| *s == '9'){
            *returnSize *= 4;
        }
        else{
            *returnSize *= 3;
        }
        ++s;
        ++len;
    }
    char ** returnStr = (char**)malloc(*returnSize*sizeof(char*));
    for(j = 0;j<*returnSize;++j){
        singleStr = (char*)malloc((len+1)*sizeof(char));
        *(singleStr+len) = '\0';
        
    loop(returnStr,len,digits);

    return returnStr;
    }
}

int main(void){
    char * s = "23";
    int returnSize,k = 0,i;
    char ** ss = letterCombinations(s,&returnSize);
    for(i = 0;i<returnSize;i++){
        printf("%s\n",*(ss+i));

    }
    return 0;
}