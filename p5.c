#include <string.h>
#include <stdio.h>
#include <stdlib.h>


// char * longestPalindrome(char * s){
//     int len = strlen(s);
//     if(len>0){
//         char* isPalind = malloc(sizeof(char)*(len*len));
//         int begin = 0;
//         int max = 1;
//         for(int i = 0;i<len;++i){
//             *(isPalind+i*len+i) = 1;
//         }
        
//         for(int i = len-1;i>=0;--i){
//             for(int j = i+1;j<len;++j){
//                 *(isPalind+i*len+j) = 0;
//                 if(s[i]==s[j]){
//                     if(i+1==j||(j>i+1&&*(isPalind+(i+1)*len+j-1))){
//                         *(isPalind+i*len+j) = 1;
//                         if(j-i+1>max){
//                             begin = i;
//                             max = j-i+1;
//                         }
//                     }
//                 }
//             }
//         }
//         char* str = (char*)malloc((max+1)*sizeof(char));
//         free(isPalind);
//         memcpy(str,s+begin,sizeof(char)*max);
//         str[max] = '\0';
//         return str;
//     }
//     else 
//         return s;
// }


/** DP
 * */

char * longestPalindrome(char * s){
    int maxStartIndex = 0;
    int maxLen = 1;
    int len = strlen(s);
    if(len>0){
        int dp[len][len];
        for(int i = 0; i<len-1;++i){
            dp[i][i] = 1;
            if(dp[i][i+1] = s[i]==s[i+1]){
                maxLen = 2;
                maxStartIndex = i;
            }
        }
        dp[len-1][len-1] = 1;
        for(int l = 3; l <= len; ++l){
            for(int i = 0; i <= len-l;++i){
                int f = dp[i][i+l-1] = dp[i+1][i+l-2]&s[i]==s[i+l-1];
                maxLen = f==1?l:maxLen;
                maxStartIndex = f==1?i:maxStartIndex;
            }
        }    
        char* result = (char*)malloc(sizeof(char)*(maxLen+1));
        memcpy(result,s+maxStartIndex,sizeof(char)*maxLen);
        result[maxLen] = '\0';
        return result;
    }
    else return "";
}


int main(void){
    char * s = "aabaababa";

    char * str  = longestPalindrome(s);
    printf("%s\n",str);


    return 0;
}
