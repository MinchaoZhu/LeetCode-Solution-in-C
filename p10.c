#include <stdio.h>
#include <stdbool.h>

bool isMatch(char* s, char* p);

bool isMatch(char* s, char* p) {
    char ch1,ch2,*sPrePointer;
    int i = 0;
    if(!*p){
        if(!*s)
            return 1;
        else
            return 0;
    }
    while(*p){//Every loop is s to p;
        ch1 = *p;
        if(!*s){
            while(*p&& *p == '*'){
                ++p;
            }
            if(*p)
                return 0;
            else
                return 1;
        }
        if(ch1 == '.'){
            if(*(p+1)){
                if(*(p+1) == '*'){
                    p+=2;
                    while(*p&&*p=='*'){
                        ++p;
                    }
                    if(*p)
                        return 0;    
                    else 
                        return 1;
                }
            }
            ++p;
            ++s;
        }
        else if(ch1 == '*'){
            ch1 = *(p-1);
            sPrePointer = s;    
            while(*s&&*s == ch1)
                ++s;
            ++p;
            if(*(s-1)!=ch1)
                continue;
            while(*p&&*(p+1)&&*(p+1)=='*'){
                p += 2;
            }
            while(*p&&*(p+i)&&*(p+i)==ch1){
                --s;
                ++i;
                if(s<sPrePointer)
                    return 0;
            }
        }
        else{
            if(*(p+1)&&*(p+1)=='*'){
                ++p;
                continue;
            }
            if(*s&&*s != ch1)
                return 0;
            ++s;
            ++p;
        }
    }
    if(*s)
        return 0;
    else    
        return 1;
}



int main(void){
    char * s = "aaab";
    char * p = "c*ab*a*aab";
    int t = isMatch(s,p);
    printf("%d\n",t);
    return 0;
}