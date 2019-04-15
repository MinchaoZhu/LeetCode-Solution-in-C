#include <stdio.h>
#include <stdbool.h>

bool isNumber(char* s) {
    bool decimalFlag = 0;
    bool eFlag = 0;
    bool signFlag = 0;
    char * ss=s;
/*omit space
*/
    while(*s==' '){
        ++s;
    }
    if(*s=='\0')return 0;
/*check sign
*/   
    if(*s=='+'||*s=='-'){
        if(*(s+1)=='\0'||!(*(s+1)=='.'||(*(s+1)>=48&&*(s+1)<=57)))
            return 0;
        ++s;
    }
    if(*s=='e')
        return 0;
/*check the digit before 'e'
*/
    while(*s){
        if(*s=='.'){
            if(decimalFlag)
                return 0;
            else{
                decimalFlag = 1;
                if(*(s+1)>=48&&*(s+1)<=57){
                }
                else if(s==ss)return 0;
                else if(*(s-1)<48||*(s-1)>57) return 0;
                ++s;
            }
        }
        else if(*s=='e'){
            eFlag = 1;
            ++s;
            break;
        }
        else if(*s>=48&&*s<=57){
            ++s;
            continue;
        }
        else if(*s==' '){
            ++s;
            while(*s){
                if(*s!=' ')
                    return 0;
                ++s;
            }
            return 1;
        }
        else
            return 0;
    }

    if(eFlag){
        if(*s=='+'||*s=='-'){++s;}
        if(*s<48||*s>57) return 0;
        while(*s){
            if(*s==' '){
                while(*s){
                    if(*s!=' ')
                        return 0;
                    ++s;
                }
                return 1; 
            }
            if(*s<48||*s>57) return 0;
            ++s;
        }
    }
    return 1;
}


int main(void){
    char * s = "4e+";
    bool t;
    t = isNumber(s);
    printf("%d\n",t);


    return 0;
}
