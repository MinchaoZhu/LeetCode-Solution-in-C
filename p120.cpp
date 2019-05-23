#include <vector>
#include <limits>
#include <iostream>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        vector<int> result(t.size(),0);
        result[0] = t[0][0];
        int pre,pre2;
        for(int i = 1;i<t.size();++i){
            pre = result[0];
            result[0] += t[i][0];
            for(int j = 1;j<i;++j){
                pre2 = result[j];
                result[j] = t[i][j] + (pre<pre2?pre:pre2);
                pre = pre2;
            }
            result[i] = pre+t[i][i];
        }

        int min = 10000;
        for(int i = 0;i<t.size();++i){
            min = result[i]<min?result[i]:min;
        }
        return min;
    }
};


int main(void){
    vector<vector<int>> t = {{2},{3,4},{6,5,7},{4,1,8,3}};
    Solution s;
    int min = s.minimumTotal(t);
    cout << min << endl;
}