#include <stdio.h>
#include <string.h>
#include <stdbool.h>


bool dfs(char *s1,char *s2, char *s3, int i1, int i2, int i3){
    int len1 = strlen(s1), len2 = strlen(s2), len3 = strlen(s3);
    if(i3==len3-1)return i1==len1-1?*(s3+i3)==*(s1+i1):*(s3+i3)==*(s2+i2);
    if(*(s1+i1)==*(s3+i3)){
        if(dfs(s1,s2,s3,i1+1,i2,i3+1)) return 1;
    }
    if(*(s2+i2)==*(s3+i3)){
        if(dfs(s1,s2,s3,i1,i2+1,i3+1)) return 1;
        
    }
    return 0;
}

bool isInterleave(char * s1, char * s2, char * s3){
    if(strlen(s1)==0&&strlen(s2)==0&&strlen(s3)==0)return 1;
    if(strlen(s3)!=strlen(s1)+strlen(s2))return 0;
    return dfs(s1,s2,s3,0,0,0);
}


int main(void){
    char * s1 = "aabcc",
         * s2 = "dbbca",
         * s3 = "aadbbbaccc";
    int t;
    t = isInterleave(s1,s2,s3);
    printf("%d\n",t);
    return 0;
}