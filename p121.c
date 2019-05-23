



int maxProfit(int* prices, int size){
    int min = INT_MAX, max = INT_MAX;
    int profit = 0;
    for(int i = 0;i<size;++i){
        if(prices[i]<min){
            profit = profit>max-min?profit:max-min;
            min = prices[i];
            max = min;
        }
        else if(prices[i]>max){
            max = prices[i];
            profit = profit>max-min?profit:max-min;
        }
    }
    return profit;
}

