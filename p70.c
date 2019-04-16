#include <stdio.h>



/*
int climbStairs(int n) {
    if(n==1)return 1;
    if(n==2)return 2;
    return climbStairs(n-1)+climbStairs(n-2);
}
*/

int climbStairs(int n) {
    int table[n];
    if(n==1)return 1;
    if(n==2)return 2;
    table[n-1] = 1;
    table[n-2] = 2;
    for(int i = n-3;i>=0;--i){
        table[i] = table[i+1]+table[i+2];
    }
    return table[0];

}


int main(void){
    int i;
    i = climbStairs(12);
    printf("%d\n",i);

    return 0;
}