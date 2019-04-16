#include <stdio.h>



/*
int climbStairs(int n) {
    if(n==1)return 1;
    if(n==2)return 2;
    return climbStairs(n-1)+climbStairs(n-2);
}
*/

int climbStairs(int n) {
    if(n==1)return 1;
    if(n==2)return 2;
    int step = 0;
    int step1 = 1;
    int step2 = 2;
    for(int i = n-3;i>=0;--i){
        step = step1+step2;
        step1 = step2;
        step2 = step;
    }
    return step;

}


int main(void){
    int i;
    i = climbStairs(12);
    printf("%d\n",i);

    return 0;
}