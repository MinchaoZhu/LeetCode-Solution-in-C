#include <stdio.h>




void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i = 0,j, temp;
    if(nums2Size==0)return;
    for(;i<m;++i){
        if(nums1[i]>nums2[0]){
            temp = nums1[i];
            nums1[i] = nums2[0];
            j = 0;
            while(j<n-1&&nums2[j+1]<temp)
                ++j;
            
            for(int k = 0;k<j;++k){
                nums2[k] = nums2[k+1];
            }
            nums2[j] = temp;
        }
    }
    for(j = 0;i<m+n;++i,++j){
        nums1[i] = nums2[j];
    }
}





int main(void){
    int nums1[6] = {2,5,6,0,0};
    int nums2[3] = {1,2,3};
    merge(nums1,6,3,nums2,3,3);
    for(int i = 0;i<6;++i){
        printf("%d ",nums1[i]);
    }
    printf("\n");

    return 0;
}