class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int size = nums.size();
        for(int i = 0; i < size; ++i){
            while(nums[i] != i + 1){
                if(nums[nums[i]-1] == nums[i])
                    return nums[i];
                int tmp = nums[i];
                nums[i] = nums[nums[i]-1];
                nums[tmp-1] = tmp;
            }
        }
        
        return -1;
    }
};