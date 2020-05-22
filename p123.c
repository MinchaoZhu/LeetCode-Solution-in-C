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


// DP

// int maxProfit(int* prices, int pricesSize){
//     if(pricesSize<2) return 0;
//     int left[pricesSize], right[pricesSize];
    
//     int minPrice = INT_MAX, maxProfit = 0; 
//     for(int i = 0; i<pricesSize; ++i){
//         minPrice = minPrice<prices[i]?minPrice:prices[i];
//         maxProfit = maxProfit>(prices[i]-minPrice)?maxProfit:(prices[i]-minPrice);
//         left[i] = maxProfit;
//     }
    
//     int maxPrice = 0;
//     maxProfit = 0;
//     for(int j = pricesSize-1; j>=0; --j){
//         maxPrice = maxPrice>prices[j]?maxPrice:prices[j];
//         maxProfit = maxProfit>(maxPrice-prices[j])?maxProfit:(maxPrice-prices[j]);
//         right[j] = maxProfit;
//     }
    
//     maxProfit = right[0];
//     for(int i = 0; i<pricesSize-1; ++i){
//         maxProfit = maxProfit>(left[i]+right[i+1])?maxProfit:(left[i]+right[i+1]);
        
//     }
    
//     return maxProfit;
// }


int main(void){
    int p[8] = {3,3,5,0,0,3,1,4};
    int max = maxProfit(p,8);
    printf("%d\n",max);
    return 0;
}