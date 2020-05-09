#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/*

public int longestValidParentheses(String s) {
    char[] S = s.toCharArray();
    int[] V = new int[S.length];
    int open = 0;
    int max = 0;
    for (int i=0; i<S.length; i++) {
        if (S[i] == '(') open++;
        if (S[i] == ')' && open > 0) {
            // matches found
            V[i] = 2+ V[i-1];
            // add matches from previous
            if(i-V[i]>0)
                V[i] += V[i-V[i]];
            open--;
        }
        if (V[i] > max) max = V[i];
    }
    return max;
}

*/
// int longestValidParentheses(char *ss){
//     if(!ss)
//         return 0;
//     if(*ss=='\0')
//         return 0;
//     char * s = ss;
//     int strLen = 0,max = 0,i,count = 0;
//     while(*s){
//         ++strLen;
//         ++s;
//     }
//     int val[strLen];
//     for(i = 0;i<strLen;++i){
//         val[i] = 0;
//     }
//     s = ss;
//     for(i = 0;i<strLen;++i,++s){
//         if(*s=='('){
//             ++count;
//         }
//         else{
//             if(count>0){
//                 val[i] = 2 + val[i-1];
//                 val[i] += (i-val[i])>0?val[i-val[i]]:0;
//                 --count;
//             }
//             else{
//                 count = 0;
//             }
//             max = val[i]>max?val[i]:max;
//         }
//     }

//     return max;
// }



//dp
int longestValidParentheses(char * s){
    int len = strlen(s);
    int max = 0;
    if(len>0){
        int dp[len];//max valid parant. ended in index i
        dp[0] = 0;

        /**
         * Inorder to solve dp[i], find the recursion formula
         * Case 1: 
         *      ()()   dp[i] = dp[i-2] + 2   (  if s[i-1] = '('  )
         * Case 2:
         *      (()())   dp[i] = dp[i-1] +2    (if s[i-5] = '(' and dp[i-1]>0)
         * Initial:
         *      dp[0] = 0
         * */
        for(int i = 1; i<len;++i){
            dp[i] = 0;
            if(s[i]==')'){
                if(s[i-1]=='('){
                    dp[i] = 2; 
                    if(i-2>0){
                        dp[i] += dp[i-2];
                    }
                }
                else{
                    if(dp[i-1]>0&&i-1-dp[i-1]>=0&&s[i-1-dp[i-1]]=='('){
                        dp[i] = 2 + dp[i-1];
                        if(i-2-dp[i-1]>0){
                            dp[i] += dp[i-2-dp[i-1]];
                        }
                    }
                }
            }
            max = max>dp[i]?max:dp[i];
        }
    }
    return max;
}


int main(void){
    char * s = "(()())";
    int max = longestValidParentheses(s);

    printf("%d\n",max);


    return 0;
}
