#include <stdio.h>
#include <stdlib.h>

// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int size1 = nums1.size(), size2 = nums2.size();
//         if((size1 + size2)%2 == 1){
//             return findKth(nums1, nums2, 0, nums1.size()-1, 0, nums2.size()-1, 1+(size1+size2)/2);
//         }
//         else{
//             return (findKth(nums1, nums2, 0, nums1.size()-1, 0, nums2.size()-1, (size1+size2)/2)+
//                    findKth(nums1, nums2, 0, nums1.size()-1, 0, nums2.size()-1, (size1+size2)/2 + 1))/2;
//         }
//     }
    
// private:
//     double findKth(vector<int>& nums1, vector<int>& nums2, int left1, int right1, int left2, int right2, int K){
//         if(left1>right1){
//             return nums2[left2 + K - 1];
//         }
//         if(left2>right2){
//             return nums1[left1 + K - 1];
//         }
        
//         if(K == 1){
//             return min(nums1[left1], nums2[left2]);
//         }
        
//         int i1 = left1 + K/2 - 1, i2 = left2 + K - (i1 - left1 + 1) -1, l1 = right1 - left1 + 1, l2 = right2 - left2 + 1;
//         if(l1>l2){
//             return findKth(nums2, nums1, left2, right2, left1, right1, K);
//         }
        
//         if(K/2 > l1){
//             i1 = left1 + l1 - 1;
//             i2 = left2 + K - (i1 - left1 + 1) - 1;
//         }

        
//         if(nums1[i1] == nums2[i2]){
//             return nums1[i1];
//         }
//         else if(nums1[i1] > nums2[i2]){
//             K = K - (i2 - left2) - 1;
//             right1 = i1;
//             left2 = i2 + 1;
//             return findKth(nums1, nums2, left1, right1, left2, right2, K);
//         }
//         else{
//             K = K - (i1 - left1) - 1;
//             left1 = i1 + 1;
//             right2 = i2;
//             return findKth(nums1, nums2, left1, right1, left2, right2, K);
//         }
        
//     }
    
// };

// double findKth(int* nums1, int size1, int* nums2, int size2, int K ){
//     if(size1 == 0){ // base case 1
//         return nums2[K-1];
//     }
    
//     if(size2 == 0){ //  base case 2
//         return nums1[K-1];
//     }
    
//     if(K == 1){ // quick solve
//         return nums1[0]<nums2[0]?nums1[0]:nums2[0];
//     }
    
//     if(size1 > size2){
//         return findKth(nums2, size2, nums1, size1, K);
//     }
    
//     int i1 = size1 < K/2 ? size1 - 1: K/2 - 1;
//     int i2 = K - (i1+1) - 1;
    
// 	// recursive step
//     if(nums1[i1] == nums2[i2]){
//         return nums1[i1];
//     }
//     else if(nums1[i1] > nums2[i2]){
//         size1 = i1+1;
//         size2 = size2 - (i2 + 1);
//         nums2 += (i2 + 1);
//         K = K - (i2 + 1);
//         return findKth(nums1, size1, nums2, size2, K);
//     }
//     else{
//         size1 = size1 - (i1 + 1);
//         size2 = i2+1;
//         nums1 += (i1 + 1);
//         K = K - (i1 + 1);
//         return findKth(nums1, size1, nums2, size2, K);
//     }
    
// }

// double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
//     int N = nums1Size + nums2Size;
//     if(N%2 == 1){
//         return findKth(nums1, nums1Size, nums2, nums2Size, N/2 + 1);
//     }
//     else{
//         double x1 = 1.0 * findKth(nums1, nums1Size, nums2, nums2Size, N/2);
//         double x2 = 1.0 * findKth(nums1, nums1Size, nums2, nums2Size, N/2 + 1);
//         return (x1+x2)/2;
//     }
    
// }




double findKthNum(int *nums1, int nums1Size, int* nums2, int nums2Size, int kN){
    int n1,n2;
    if(nums1Size == 0)
        return *(nums2+kN-1);
    else if(nums2Size == 0)
        return *(nums1+kN-1);
    if(kN == 1)
        return (*nums1 < *nums2)?*nums1:*nums2;
    if(nums1Size>nums2Size)
        return findKthNum(nums2,nums2Size,nums1,nums1Size,kN);
    n1 = (kN/2>nums1Size)?nums1Size:kN/2;
    n2 = kN - n1;
   // if(nums1Size == 1)
     //   return *(nums2+n2-1);

    if(*(nums1+n1-1)==*(nums2+n2-1))
        return *(nums1+n1-1);
    else if(kN == 1)
        return (*nums1<*nums2)?*nums1:*nums2;
    else
    {
        if(*(nums1+n1-1)>*(nums2+n2-1)){
            return findKthNum(nums1,n1,nums2+n2,nums2Size-n2,kN-n2);
        }
        else
        {
            return findKthNum(nums1+n1,nums1Size-n1,nums2,n2,kN-n1);
        }
        
    }

}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int N = nums1Size + nums2Size, num1,num2;    
    if(N%2)
        return findKthNum(nums1, nums1Size, nums2, nums2Size ,(N+1)/2);
    else
    {
        num1 = findKthNum(nums1, nums1Size, nums2, nums2Size ,N/2);
        num2 = findKthNum(nums1, nums1Size, nums2, nums2Size ,N/2+1);
        return (findKthNum(nums1, nums1Size, nums2, nums2Size ,N/2)+findKthNum(nums1, nums1Size, nums2, nums2Size ,N/2+1))/2.0;
    }
}





int main(void){
    int nums1[6] = {2,3,4,6,7,8};
    int nums2[2] = {1,5};
    double median = findMedianSortedArrays(nums1,6,nums2,2);
    printf("%lf\n",median);
    return 0;
}
