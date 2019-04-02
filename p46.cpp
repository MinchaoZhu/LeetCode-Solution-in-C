#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        recursive(result, nums, 0, nums.size);
        return result;
    }
private:
    void recursive(vector<vector<int>>& result, vector<int>& nums,int begin,int end){
        if(begin==end){
            result.push_back(nums);
            return;
        }
        for(int i = begin;i<end;++i){
            swap(nums[i],nums[begin]);
            recursive(result,nums,begin+1,end);
            swap(nums[i],nums[begin]);
        }
    }
};



int main(void){




    return 0;
}