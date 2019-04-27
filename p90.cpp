#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        vector<vector<int>> result;
        for(int i=0;i<nums.size()+1;++i){
            vector<int> temp;
            combine(result,nums,temp,0,i);
        }
        return result;
    }

    static bool cmp(int a, int b){
        return a<b;
    }

private:
    void combine(vector<vector<int>>& result, vector<int>& nums, vector<int>& temp, int start, int i){
        if(i==0)result.push_back(temp);
        else{
            for(int cur = start;cur<nums.size();++cur){
                if(cur>start&&nums[cur]==nums[cur-1])continue;
                temp.push_back(nums[cur]);
                combine(result,nums,temp,cur+1,i-1);
                temp.pop_back();
            }
        }
    }
};



int main(void){
    Solution s;
    vector<int> nums = {1,2,2};
    vector<vector<int>> result;
    result = s.subsetsWithDup(nums);

    return 0;
}