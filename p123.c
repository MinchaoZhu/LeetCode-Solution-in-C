#include <limits.h>
#include <stdio.h>

#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))

int maxProfit(int* p, int size){
    if(size>0){
        int cost1 = INT_MAX, cost2  = INT_MAX;
        int profit1 = 0, profit2 = 0;
        for(int i = 0;i<size;++i){
            cost1 = min(cost1,p[i]);
            profit1 = max(profit1, p[i]-cost1);
            cost2 = min(cost2,p[i]-profit1);
            profit2 = max(profit2,p[i]-cost2);
        }
        return profit2;
    }
    else return 0;
}

int main(void){
    int p[8] = {3,3,5,0,0,3,1,4};
    int max = maxProfit(p,8);
    printf("%d\n",max);
    return 0;
}