#include <stdio.h>

int candy(int* ratings, int ratingsSize){
    int candies[ratingsSize];
    int result = 0;
    for(int i = 0;i<ratingsSize;++i)candies[i] = 1;
    if(ratingsSize>1&&ratings[0]>ratings[1])candies[0] = candies[1] + 1;
    for(int i = 1;i<ratingsSize-1;++i){
        if(ratings[i]>ratings[i-1]) candies[i] = candies[i]>(candies[i-1] + 1)?candies[i]:(candies[i-1]+1);;
    }
    //printArr(candies,ratingsSize);
    if(ratingsSize>1&&ratings[ratingsSize-1]>ratings[ratingsSize-2]) candies[ratingsSize-1] = candies[ratingsSize-2] + 1;
    for(int i = ratingsSize-2;i>0;--i){
        if(ratings[i]>ratings[i+1]) candies[i] = candies[i]>(candies[i+1] + 1)?candies[i]:(candies[i+1]+1);
    }
    if(ratingsSize>1&&ratings[0]>ratings[1])candies[0] = candies[1] + 1;
    for(int i = 0;i<ratingsSize;++i)result+=candies[i];
    //printArr(candies,ratingsSize);
    return result;
}

void printArr(int * arr, int size){
    for(int i = 0;i<size;++i)
        printf("%d \n",arr[i]);
    printf("\n");
}

int main(void){
    int arr[6] = {1,2,3,3,3,2};
    int result;
    result = candy(arr,6);
    printf("result = %d\n",result);
    return 0;
}