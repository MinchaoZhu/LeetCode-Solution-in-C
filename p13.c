#include <stdio.h>


int romanToInt(char* s) {
    int r = 0;
    while(*s&&*s == 'M'){
        r += 1000;
        ++s;
    }
    if(*s&&*s == 'D'){
        r += 500;
        ++s;
    }
    if(*s&&*s == 'C'){
        ++s;
        if(*s&&*s == 'M'){
            r += 900;
            ++s;
        }    
        else if(*s&&*s == 'D'){
            r += 400;
            ++s;
        }
        else{
            r += 100;
            while(*s&&*s == 'C'){
                r += 100;
                ++s;
            }
        }
    }
    if(*s&&*s == 'L'){
        r += 50;
        ++s;
    }
    if(*s&&*s == 'X'){
        ++s;
        if(*s&&*s == 'C'){
            r += 90;
            ++s;
        }    
        else if(*s&&*s == 'L'){
            r += 40;
            ++s;
        }
        else{
            r += 10;
            while(*s&&*s == 'X'){
                r += 10;
                ++s;
            }
        }
    }
    if(*s&&*s == 'V'){
        r += 5;
        ++s;
    }
    if(*s&&*s == 'I'){
        ++s;
        if(*s&&*s == 'X'){
            r += 9;
            ++s;
        }
        else if(*s&&*s == 'V'){
            r += 4;
        }
        else{
            r += 1;
            while(*s&&*s == 'I'){
                r += 1;
                ++s;
            }            
        }
    }
    return r;
}


int main(void){
    char* s = "LVIII";
    int r;
    r = romanToInt(s);
    printf("%d\n",r);

    return 0;
}