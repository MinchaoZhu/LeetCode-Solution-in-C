#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> temp;
        recur(result,temp,n,1,k);
        return result;
    }   

private:
    void recur(vector<vector<int>>& result, vector<int>& temp, int n, int start, int k){
        if(!k){
            result.push_back(temp);
            return;
        }
        else{
            for(int cur = start;cur<n+1&&(cur+k)<=n+1;++cur){
                temp.push_back(cur);
                recur(result,temp,n,cur+1,k-1);
                temp.pop_back();
            }
        }
    }
};



int main(void){
    vector<vector<int>> r;

    return 0;
}