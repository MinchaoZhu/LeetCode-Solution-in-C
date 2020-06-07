class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.size()>1){
            vector<int> left(nums.size());
            vector<int> right(nums.size());
            vector<int> result(nums.size());

            int p = 1;
            for(int i = 0; i<nums.size(); ++i){
                left[i] = (p*=nums[i]);
            }
            p = 1;
            for(int j = nums.size()-1; j>0; --j){
                right[j] = (p*=nums[j]); 
            }

            result[0] = right[1];
            result[nums.size()-1] = left[nums.size()-2];

            for(int i = 1; i<nums.size()-1; ++i){
                result[i] = left[i-1] * right[i+1];
            }
            return result;
        }
        else return vector<int>();
        
        
        
    }
};