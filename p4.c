#include <stdio.h>
#include <stdlib.h>





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
