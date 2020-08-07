class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> exist(nums.begin(), nums.end());
        int result = 0;
        for(const auto& num : nums) {
            if(exist.find(num-1) == exist.end()) {
                int len = 1, cur = num + 1;
                while(exist.find(cur) != exist.end()) {
                    ++len;
                    ++cur;
                }
                
                result = max(result, len);
            }
            
        }
        
        
        
        return result;
        
    }
};