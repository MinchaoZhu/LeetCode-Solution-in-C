#include <stdio.h>


/*
int uniquePaths(int m, int n) {
    if(m==1)
        return 1;
    if(n==1)
        return 1;
    return
        uniquePaths(m-1,n)+uniquePaths(m,n-1);
}
*/

int uniquePaths(int m, int n){
    int table[m][n];
    int i,j;
    for(i=0;i<n;++i){
        table[m-1][i] = 1;
    }
    for(i=0;i<m;++i){
        table[i][n-1] = 1;
    }
    if(m==1||n==1)return 1;
    --m;
    --n;
    while(m>0&&n>0){
        for(i = n-1;i>=0;--i){
            table[m-1][i] = table[m][i]+table[m-1][i+1];
        }
        for(i = m-2;i>=0;--i){
            table[i][n-1] = table[i+1][n-1]+table[i][n];
        }
        --m;--n;
    }
    if(m==0){
        if(n!=0){
            for(i = n-1;i>=0;--i){
                table[0][i] = table[1][i]+table[0][i+1];
            }
            return table[0][0];
        }
        if(n==0)
            return table[1][0]+table[0][1];
    }
    if(m!=0){
        for(i = m-1;i>=0;--i){
            table[i][0] = table[i+1][0]+table[i][1];
        }        
        return table[0][0];
    }
    return table[0][0];
}


int main(void){
    int sum = 0;
    sum = uniquePaths(5,2);
    printf("%d\n",sum);

    return 0;
}