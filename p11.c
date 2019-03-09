#include <stdio.h>


int maxArea(int* height, int heightSize) {
    int left = 0, right = heightSize-1,max = 0,temp = 0;
    while(right>left){
        if(*(height+left)>*(height+right)){
            temp = *(height+right)*(right-left);
            max = temp>max?temp:max;
            --right;
        }
        else{
            temp = *(height+left)*(right-left);
            max = temp>max?temp:max;
            ++left;            
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