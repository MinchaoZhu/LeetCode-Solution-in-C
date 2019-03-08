#include <stdio.h>
#include <stdbool.h>


bool isPalindrome(int x);





bool isPalindrome(int x)  {
    if(x<0)
        return 0;
    else if(!x)
        return 1;
    int digitTable[10];
    int i = 0,j = 0;
    while(x){
        digitTable[i++] = x%10;
        x /= 10;
    }
    --i;
    while(j<i){
        if(digitTable[i--]!=digitTable[j++])
            return 0;
    }
    return 1;
}


int main(void){
    int x = 1232;
    int yes = isPalindrome(x);
    printf("%d\n",yes);
    return 0;
}