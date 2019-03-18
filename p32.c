#include <stdio.h>
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
int longestValidParentheses(char *ss){
    if(!ss)
        return 0;
    if(*ss=='\0')
        return 0;
    char * s = ss;
    int strLen = 0,max = 0,i,count = 0;
    while(*s){
        ++strLen;
        ++s;
    }
    int val[strLen];
    for(i = 0;i<strLen;++i){
        val[i] = 0;
    }
    s = ss;
    for(i = 0;i<strLen;++i,++s){
        if(*s=='('){
            ++count;
        }
        else{
            if(count>0){
                val[i] = 2 + val[i-1];
                val[i] += (i-val[i])>0?val[i-val[i]]:0;
                --count;
            }
            else{
                count = 0;
            }
            max = val[i]>max?val[i]:max;
        }
    }

    return max;
}


int main(void){
    char * s = "(()((()))";
    int max = longestValidParentheses(s);

    printf("%d\n",max);


    return 0;
}
