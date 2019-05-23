#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
       vector<vector<int>> result;
       genFunc(result,numRows); 
       return result;
    }

private:
    void genFunc(vector<vector<int>>& result, int numRows){
        for(int j=0;j<numRows;++j){
            vector<int> temp(j+1,1);
            for(int i=1;i<j;++i){
                temp[i] = result[j-1][i-1]+result[j-1][i];
            }
            result.emplace_back(temp);
        }
    }
};



int main(void){
    Solution s;
    s.generate(5);


    return 0;
}