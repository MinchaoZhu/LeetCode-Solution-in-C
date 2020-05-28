class NumArray {
private:
    vector<int> sum = {0};
public:
    NumArray(vector<int>& nums) {
        int tmp = 0;
        for(auto num:nums){
            tmp += num;
            sum.emplace_back(tmp);
        }
    }
    
    int sumRange(int i, int j) {
        return sum[j+1]-sum[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */