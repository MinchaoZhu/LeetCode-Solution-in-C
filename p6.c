#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tableLen 10





char* convert(char* s, int numRows) {
    if(!*s)
        return s;
    if(numRows == 1)
        return s;
    char * chTable[numRows],*temp, * returnStr;
    int i = 0, j = 0, sLen = 0, tableSeqNum = 0;
    int outputSeq[2*numRows - 2];
    int tableSize[numRows], tableAccess[numRows];
    for(i = 0;i<numRows;++i){
        outputSeq[i] = i;
        tableSize[i] = 0;
        tableAccess[i] = tableLen;
    }
    for(j = numRows-2;i<2*numRows-2;++i,--j){
        outputSeq[i] = j;
    }
    for(i = 0;i<numRows;++i){
        chTable[i] = (char*)malloc(tableLen*sizeof(char));
        *(chTable[i]) = '\0';
    }
    while(*s){
        tableSeqNum = outputSeq[sLen%(2*(numRows-1))];
        if(tableSize[tableSeqNum] == tableAccess[tableSeqNum]){
            temp = (char*)malloc((tableAccess[tableSeqNum]+tableLen)*sizeof(char));
            memcpy(temp,chTable[tableSeqNum],tableSize[tableSeqNum]);
            free(*(chTable+tableSeqNum));
            chTable[tableSeqNum] = temp;
            tableAccess[tableSeqNum] = tableAccess[tableSeqNum]+tableLen;
        }
        *(chTable[tableSeqNum]+tableSize[tableSeqNum]) = *s;
        *(chTable[tableSeqNum]+tableSize[tableSeqNum]+1) = '\0';
        ++tableSize[tableSeqNum];
        ++sLen;
        ++s;
    }
    returnStr = (char*)malloc((sLen+1)*sizeof(char));
    *(returnStr+sLen) = '\0';
    sLen = 0;
    for(i = 0; i<numRows;++i){
        j = 0;
        while(*(chTable[i]+j)){
            *(sLen+returnStr) = *(chTable[i]+j);
            ++j;
            ++sLen;
        }
    }
    return returnStr;
}

int main(void){
    char * s = "Apalindromeisaword,phrase,number,orothersequenceofunitsthatcanbereadthesamewayineitherdirection,withgeneralallowancesforadjustmentstopunctuationandworddividers.";
    int numRows = 2;
    s = convert(s,numRows);
    printf("%s\n",s);
    return 0;
}