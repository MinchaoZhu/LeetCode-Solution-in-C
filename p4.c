#include <stdio.h>
#include <stdlib.h>




double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int size = nums1Size+nums2Size;
    int * newArr = (int*)malloc(size*sizeof(int));
    int i1 = 0,i2 = 0,i = 0, med1Position,med2Position;
    if(size%2){
        med1Position = (size-1)/2;
        med2Position =med1Position;
    }
    else{
        med1Position = (size -1)/2;
        med2Position = med1Position + 1;
    }
    if(nums1Size == 0){
        return 1.0 * (*(nums2+med1Position)+*(nums2+med2Position))/2;
    }
    else if (nums2Size == 0){
        return 1.0 * (*(nums1+med1Position)+*(nums1+med2Position))/2;
    }
    
    for(;i<size;++i){
        *(newArr+i) = *(nums1+i1)<*(nums2+i2)?*(nums1+(i1++)):*(nums2+(i2++));
        if(i == med2Position)
            return 1.0 *(*(newArr+med1Position)+*(newArr+med2Position))/2;
        if((i1 == nums1Size)||(i2 == nums2Size))
            break;
    }
    ++i;
    if(i1 == nums1Size){
        for(;i2<nums2Size;++i2){
            *(newArr+i) = *(nums2+i2); 
            if(i == med2Position)
                return 1.0 *(*(newArr+med1Position)+*(newArr+med2Position))/2;
            ++i;    
        } 
    }
    else{
        for(;i1<nums1Size;++i1){
            *(newArr+i) = *(nums1+i1); 
            if(i == med2Position)
                return 1.0 *(*(newArr+med1Position)+*(newArr+med2Position))/2;
            ++i;    
        } 
    }

    return 1.0 *(*(newArr+med1Position)+*(newArr+med2Position))/2;
}






int main(void){
    int nums1[2] = {1,2};
    int nums2[2] = {3,4};
    double median = findMedianSortedArrays(nums1,2,nums2,2);
    printf("%lf\n",median);

    return 0;
}
