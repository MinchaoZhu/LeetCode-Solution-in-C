#include <stdio.h>
#include <string.h>
#include <stdbool.h>



bool isPalindrome(char * s){
    int len = strlen(s);
    int first = 0, end = len - 1;
    while(first<end){
        while(first<end&&!(('0'<=*(s+first)&&*(s+first)<='9')||('A'<=*(s+first)&&*(s+first)<='Z')||('a'<=*(s+first)&&*(s+first)<='z')))++first;
        while(first<end&&!(('0'<=*(s+end)&&*(s+end)<='9')||('A'<=*(s+end)&&*(s+end)<='Z')||('a'<=*(s+end)&&*(s+end)<='z')))--end;
        if(first<end)
            if(!(*(s+first)==*(s+end)||(('A'<=*(s+first)&&*(s+first)<='Z')&&(*(s+first)+'a'-'A')==*(s+end))||(('a'<=*(s+first)&&*(s+first)<='z')&&*(s+first)==(*(s+end)+'a'-'A'))))
                return 0;
        ++first, --end;
    }
    return 1;
}




int main(void){
    int b;
    char * s = "0P";
    b = isPalindrome(s);
    printf("%d\n", b);
    return 0;
}