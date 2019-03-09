#include <stdio.h>


int maxArea(int* height, int heightSize) {
    int left = 0, right = 1,max = 0,temp = 0;
    for(;left<heightSize-1;++left){
        for(right = left+1;right<heightSize;++right){
            temp = *(height+left)>*(height+right)?*(height+right)*(right-left):*(height+left)*(right-left);
            if(temp>max)
                max = temp;
        }
    }
    return max;
}

int main(void){
    int height[9] = {1,8,6,2,5,4,8,3,7};
    int size = 9;
    int re = maxArea(height,size);
    printf("%d\n",re);


    return 0;
}