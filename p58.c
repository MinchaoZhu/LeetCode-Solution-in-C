#include <stdio.h>
#include <stdbool.h>

int lengthOfLastWord(char* s) {
    char* start = s, *end = s-1;
    bool status = 1;//0: space, 1: word
    while(*s){
        if(*s == ' '){
            if(status!=0){
                status = 0;
            }
        }
        else{
            if(status){
                ++end;
            }
            else{
                status = 1;
                start = s;
                end = s;
            }
        }
        ++s;
    }
    return end-start+1;
}

int main(void){



    return 0;
}