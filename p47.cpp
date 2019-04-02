#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        rec(result,nums,0);
        return result;
    }

private:
    void rec(vector<vector<int>>& result, vector<int> nums, int begin){
        if(begin>=nums.size()){
            result.push_back(nums);
            return;
        }
        for(int i = begin; i< nums.size();++i){
            if (i > begin && nums[begin] == nums[i]) 
                continue;
            swap(nums[i],nums[begin]);
            rec(result,nums,begin+1);
            //swap(nums[i],nums[begin]);
        }
    }
};

/*
class Solution {
    vector<vector<int>> ans;

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        perm(nums, 0, nums.size() - 1);
        return ans;
    }
    
    void perm(vector<int> nums, int left, int right) {
        if (left == right)
            ans.push_back(nums);
        else {
            for (int i = left; i <= right; i++) {
                if (i != left && nums[left] == nums[i]) continue; 
                swap(nums[left], nums[i]);
                perm(nums, left + 1, right);
            }
        }
    }
};/*
*/


int main(void){
    vector<int> nums = {2,2,1,1};
    vector<vector<int>> re;
    Solution S;
    re = S.permuteUnique(nums);
    int size = re.size();
    for(int i = 0;i<size;++i){
        int size2 = re[i].size();
        for(int j = 0;j<size2;++j){
            cout<< re[i][j] << ' ';
        }
        cout << endl;
    }
    cout<<size<<endl;
    return 0;
}