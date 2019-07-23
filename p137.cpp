#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> numsMap;
        int result;
        for(auto num : nums){
            if(numsMap.find(num)==numsMap.end()){
                numsMap.insert(pair<int,int>(num,1));
            }
            else{
                numsMap.find(num)->second += 1;
            }
        }
        for(auto iter : numsMap){
            if(iter.second==1)
                result = iter.first;
        }
        return result;
    }
};