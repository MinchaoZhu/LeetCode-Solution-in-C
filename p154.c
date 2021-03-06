
int myMin(int a, int b){
    return a<b?a:b;
}

int recur(int* nums, int begin, int end){
    if(end-begin>1){
        int mid = (begin+end)/2;
        if(nums[end]>nums[begin]){
            if(nums[mid]>nums[end])
                return recur(nums,mid,end);
            else 
                return recur(nums,begin,mid);
        }
        else{
            if(nums[mid]>nums[end])
                return recur(nums,mid,end);
            else if(nums[mid]==nums[end])
                return myMin(recur(nums,begin,mid-1),recur(nums,mid,end));
            else
                return recur(nums,begin,mid);
        }
    }
    else return myMin(nums[begin],nums[end]);
}

int findMin(int* nums, int numsSize){
    return recur(nums, 0, numsSize-1);
}

