#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> result;
        int minNum,maxNum,midNum;
        minNum = min(c,min(a,b));
        maxNum = max(c,max(a,b));
        midNum = minNum^maxNum^a^b^c;
        int temp1 = midNum-minNum, temp2 = maxNum-midNum;
        if(temp1==1&&temp2==1)result.push_back(0);
        else if(temp1==1||temp2==1||temp1==2||temp2==2)result.push_back(1);
        else result.push_back(2);
        result.push_back(midNum-minNum-2+maxNum-midNum);  

        return result;

    }
};







int main(void){
    Solution s;
    vector<int> re;
    re = s.numMovesStones(3,5,1);
    cout<<re[0]<<endl;
    cout<<re[1]<<endl;

    return 0;
}