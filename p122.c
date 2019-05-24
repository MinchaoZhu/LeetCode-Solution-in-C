

int maxProfit(int* prices, int size){
    int profit = 0;
    if(size){
        int min = prices[0], max = prices[0];
        for(int i = 1;i<size;++i){
            if(prices[i]<max){
                profit+=max-min;
                max = prices[i];
                min = prices[i];
            }
            else max = prices[i];
        }
        profit+=max-min;
    }
    return profit;
}

