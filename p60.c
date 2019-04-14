#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int find(bool*flag,int pos,int size){
    for(int i = 0;i<size;++i){
        if(!flag[i])
            --pos;
        if(pos<0)
            return i;
    }
    return size-1;
}

char* getPermutation(int n, int k) {
    bool flag[n];
    int i;
    char * result;
    result = (char*)malloc(sizeof(char)*(n+1));
    for(i = 0;i<n;++i){
        flag[i] = 0;
    }
    int num = 1;
    for(i = 1;i<n;++i){
        num*=i;
    }
    int pos = 0,t = n-1;
    for(i = 0;i<n-1;++i,--t){
        pos = (k-1)/num;
        k -=pos*num;
        num/=t>0?t:1;
        *(result+i) = find(flag,pos,n)+'1';
        flag[*(result+i)-'1'] = 1;
    }
    *(result+i) = find(flag,0,n)+'1';
    *(result+n) = '\0';
    return result;
}


int main(void){
    char* re;
    re = getPermutation(4,9);
    printf("%s",re);


    return 0;
}