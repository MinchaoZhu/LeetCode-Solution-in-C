#include <string.h>
#include <stdio.h>
struct cell{
    char ch;
    int pos;
};

int lengthOfLongestSubstringTwoDistinct(char * s){
    int len = strlen(s),max = 2, sub = 2;
    if(len>=3){
        int cur0 = 0, cur1 = 1;
        int cell1Exist = 0;
        struct cell cell0,  cell1;
        cell0.ch = s[0], cell0.pos = 0;
        cell1.ch = s[1], cell1.pos = 1;
        if(s[0]!=s[1])cell1Exist=1;
        ++cur1;
        while(cur1<len){
            if(s[cur1]!=cell0.ch&&s[cur1]!=cell1.ch){
                if(cell1Exist){
                    max = max>sub?max:sub;
                    cell0.ch = cell1.ch;
                    cell0.pos = cell1.pos;
                    cell1.ch = s[cur1];
                    cell1.pos = cur1;
                    sub = cur1-cell0.pos+1;
                }
                else{
                    cell1.ch = s[cur1];
                    cell1.pos = cur1;
                    sub = cur1-cell0.pos;
                    cell1Exist = 1;
                    ++sub;
                }
            }
            else if(s[cur1]==cell0.ch){
                if(cell1Exist){
                    cell0.ch = cell1.ch;
                    cell0.pos = cell1.pos;
                    cell1.ch = s[cur1];
                    cell1.pos = cur1;
                }
                ++sub;
            }
            else{
                ++sub;
            }
            ++cur1;
        }
        max = max>sub?max:sub;
        return max;
    }
    else return 0;
}

int main(void){
    char *s = "ccaabbb";
    int n = lengthOfLongestSubstringTwoDistinct(s);
    printf("%d\n",n);


    return 0;
}