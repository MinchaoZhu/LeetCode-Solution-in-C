
#include <stdio.h>



typedef struct slopeType{
    int slope;
    int pos;
}slopeType;

#define II 0
#define DD 3
#define ID 1
#define DI 2

/*
II 00
DD 11
ID 01
DI 10
*/





slopeType func(int* nums, int begin, int last, int lastPos){
    slopeType slope1, slope2;
    if(last-begin==1){
        if(begin==0&&last!=lastPos){
            if(nums[last]<nums[begin]){
                slope1.pos = 0;
                slope1.slope = ID;
                return slope1;
            }
            else{
                slope1.slope = II;
                return slope1;
            }
        }
        else if(begin!=0&&last==lastPos){
            if(nums[begin]<nums[last]){
                slope1.pos = last;
                slope1.slope = ID;
                return slope1;
            }
            else{
                slope1.slope = DD;
                return slope1;
            }
        }
        else if(begin==0&&last==lastPos){
            slope1.pos = nums[0]>nums[1]?0:1;
            slope1.slope = ID;
            return slope1;
        }
        else{
            slope1.slope = nums[begin]>nums[last]?DD:II;
            return slope1;
        }
    }
    else if(last-begin==2){
        int mid = (begin+last)/2;
        int slopeTemp = 0;
        if(nums[mid]>nums[last]) slopeTemp |= 1;
        if(nums[begin]>nums[mid]) slopeTemp |= 2;
        slope1.slope = slopeTemp;
        if(slopeTemp==ID) slope1.pos = mid; 
        if(begin==0&&(slopeTemp&2)){
            slope1.slope = ID;
            slope1.pos = 0;
        }
        if(last== lastPos&&(slopeTemp==II||slopeTemp==DI)){
            slope1.slope = ID;
            slope1.pos = lastPos;
        }
        return slope1;
    }
    else{
        int mid = (begin+last)/2;
        slope1 = func(nums,begin,mid,lastPos);
        if(slope1.slope == ID) return slope1;
        slope2 = func(nums,mid+1,last,lastPos);
        if(slope2.slope == ID) return slope2;
        
        if((slope1.slope==DI||slope1.slope==II)&&(slope2.slope==DI||slope2.slope==DD)){
            slope1.pos = nums[mid]>nums[mid+1]?mid:mid+1;
            slope1.slope = ID;
            return slope1;
        }
        if(slope1.slope==II&&slope2.slope==II){
            if(nums[mid+1]<nums[mid]){
                slope1.slope = ID;
                slope1.pos = mid;
                return slope1;
            }
            else return slope1;
        }
        if(slope1.slope==DD&&slope2.slope==DD){
            if(nums[mid+1]>nums[mid]){
                slope1.slope = ID;
                slope1.pos = mid;
                return slope1;
            }
            else return slope1;
        }
    }
    return slope1;
}




int findPeakElement(int* nums, int numsSize){
    if(numsSize>1){
        slopeType slope = func(nums,0,numsSize-1, numsSize-1);
        return slope.pos;
    }
    else return 0;
}

int main(void){
    int arr[7] = {3,2,1,4,5,6,4};
    int t;
    t = findPeakElement(arr,3);
    printf("%d\n",t);
    return 0;
}