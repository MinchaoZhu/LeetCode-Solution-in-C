class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int len = nums.size();
        vector<int> result;
        
        for(int i = 0; i < len; ++i) {
            while(nums[i] > 0 && nums[i] != i+1) {
                int tmp = nums[nums[i]-1];
                if(tmp == nums[i]){
                    nums[nums[i]-1] = -tmp;
                    result.emplace_back(tmp);
                    break;
                }
                nums[nums[i]-1] = nums[i];
                nums[i] = tmp;
            }
            
        }
        
        return result;
        
    }
};