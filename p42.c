#include <stdio.h>

// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int l = 0, r = height.size()-1;
//         int ml = 0, mr = 0, res = 0;
//         while (l < r) {
//             if (height[l] < height[r]) {
//                 ml = max(ml, height[l]);
//                 res += ml - height[l];
//                 ++l;
//             } else {
//                 mr = max(mr, height[r]);
//                 res += mr - height[r];
//                 --r;
//             }
//         }
//         return res;
//     }
// };

// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int size = height.size();
//         if(size>2){
//             int left[size];
//             int right[size];
            
//             int tmp = 0;
//             for(int i = 0; i<size; ++i){
//                 left[i] = tmp;
//                 tmp = tmp>height[i]?tmp:height[i];
//             }
            
//             tmp = 0;
//             for(int i = size-1; i>=0; --i){
//                 right[i] = tmp;
//                 tmp = tmp>height[i]?tmp:height[i];
//             }
            
//             tmp = 0;
//             for(int i = 0; i<size; ++i){
//                 int h = min(left[i], right[i]);
//                 tmp += h>height[i]?h-height[i]:0;
//             }
            
//             return tmp;
            
//         }
//         else return 0;
//     }
// };


int trap(int* h, int n) {
    int high=h[0], left = 0;
    int right = 1, hightest=h[1],posOfHisghest=0;
    int i = 0;
    int S = 0;
    while(right<n){
        high = h[left];
        hightest = h[right];
        posOfHisghest = right;
        while(right<n&&h[right]<high){
            if(h[right]>hightest){
                hightest = h[right];
                posOfHisghest = right;
            }
            ++right;
        }
        if(right<n){
            for(i = left+1;i<right;++i){
                S += high-h[i];
            }
            left = right;
            ++right;
        }
        else{
            right = posOfHisghest;
            high = h[posOfHisghest];
            for(i = left+1;i<right;++i){
                S += high-h[i];
            }            
            left = right;
            ++right;
        }
    }
    return S;
}

int main(void){
    int A[12] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int S;
    S = trap(A,12);
    printf("%d\n",S);



}