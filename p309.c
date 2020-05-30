int f_max(int a, int b){
    return a>b?a:b;
}

int maxProfit(int* prices, int pricesSize){
    if(pricesSize>1){
        int rest[pricesSize];
        int hold[pricesSize];
        int sell[pricesSize];
        rest[0] = 0;
        hold[0] = 0-prices[0];
        sell[0] = 0;
        for(int i = 1; i<pricesSize; ++i){
            rest[i] = f_max(rest[i-1], sell[i-1]);
            hold[i] = f_max(hold[i-1], rest[i-1] - prices[i]);
            sell[i] = hold[i-1] + prices[i];
        }
        return f_max(sell[pricesSize-1], rest[pricesSize-1]);
    }
    else return 0;
}