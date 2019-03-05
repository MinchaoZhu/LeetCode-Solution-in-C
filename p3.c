/*
 * @Author: Minchao Zhu 
 * @Date: 2019-03-05 12:37:59 
 * @Last Modified by: Minchao Zhu
 * @Last Modified time: 2019-03-05 13:10:15
 */

#include <stdio.h>

int lengthOfLongestSubstring(char* s)
{
    int len=0;
    char * addressTable[128] = {NULL};//the table to store the laste address of letters
    char * subStrHead = s;//the header of present subString

    while(*s){
        if(subStrHead <= addressTable[*s]){//if we find the same letters after the previous subString header, re-calculate the length between the same letters. (Bettwen two same letters, there are no other identical letters.)
            len = (s-addressTable[*s]) > len ? s-addressTable[*s] : len;// compare the length of new subString bettwen these same letter and the existent max length.
            subStrHead = addressTable[*s] + 1;//new subString starts in the next position after the first letter of the same.
            addressTable[*s] = s; // update the address table
        }
        else{
            len = (s - subStrHead + 1) > len ? s - subStrHead + 1 : len;
            addressTable[*s] = s;// if there is no identical letter, adding the address and calculate the length.
        }
        ++s;
    }
    len = (s-subStrHead) > len ? s-subStrHead : len; // finally, check the last subString ends with the last latter of string s
    return len;
}


int main(void){
    char* str = "abbcda";
    int max = lengthOfLongestSubstring(str);
    printf("%d \n", max);
    return 0;
}
