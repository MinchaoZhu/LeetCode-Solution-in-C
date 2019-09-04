#include <string.h>
#include <stdio.h>
#include <stdlib.h>


char * longestPalindrome(char * s){
    int len = strlen(s);
    if(len>0){
        char* isPalind = malloc(sizeof(char)*(len*len));
        int begin = 0;
        int max = 1;
        for(int i = 0;i<len;++i){
            *(isPalind+i*len+i) = 1;
        }
        
        for(int i = len-1;i>=0;--i){
            for(int j = i+1;j<len;++j){
                *(isPalind+i*len+j) = 0;
                if(s[i]==s[j]){
                    if(i+1==j||(j>i+1&&*(isPalind+(i+1)*len+j-1))){
                        *(isPalind+i*len+j) = 1;
                        if(j-i+1>max){
                            begin = i;
                            max = j-i+1;
                        }
                    }
                }
            }
        }
        char* str = (char*)malloc((max+1)*sizeof(char));
        free(isPalind);
        memcpy(str,s+begin,sizeof(char)*max);
        str[max] = '\0';
        return str;
    }
    else 
        return s;
}


int main(void){
    char * s = "abcda";

    char * str  = longestPalindrome(s);
    printf("%s\n",str);


    return 0;
}
