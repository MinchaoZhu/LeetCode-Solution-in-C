#include <stdio.h>

/*
int jump(int* nums, int n) {
    if (n == 1) return 0;
    
    int count = 1, i = 0, j = 0, mx_idx = 0;
    
    while (i+nums[i] < n-1) {
        j = i; mx_idx = j;
        while (j <= i+nums[i] && j < n) {
            if (mx_idx + nums[mx_idx] < j + nums[j])
                mx_idx = j;
            j++;
        }
        
        i = mx_idx;
        count++;
    }
    
    return count;
}
*/
int jump(int* nums, int n) {
    if(n==1)
        return 0;
    int pos = 0, step = 0;
    int maxPos, j;
    while(pos+nums[pos]<n-1){
        j = pos+1;
        maxPos = pos+1;
        for(;j<(pos+nums[pos]+1)&&j<n;++j){
            if(maxPos+nums[maxPos]<j+nums[j]){
                maxPos = j;
            }
        }
        pos = maxPos;
        ++step;
    }
    return step+1;
}




int main(void){
    int A[20] = {9,8,2,2,0,2,2,0,4,1,5,7,9,6,6,0,6,5,0,5};
    int x;
    //int A[5] = {2,3,1,1,4};
    x = jump(A,20);
    printf("%d\n",x);

    return 0;
}