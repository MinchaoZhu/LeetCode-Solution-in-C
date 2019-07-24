#include <vector>
#include <string>
#include <set>
#include <iostream>
using namespace std;


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int strlen = s.length(), cur = strlen-1;
        if(strlen<=0) return 0;
        set<string> strSet;
        strSet.insert(wordDict.begin(),wordDict.end());
        vector<int> memo(strlen+1,0);
        memo[strlen] = 1;
        for(;cur>=0;--cur){
            for(int i = cur+1;i<=strlen;++i){
                if(memo[i]==1){
                    if(strSet.find(s.substr(cur,i-cur))!=strSet.end()){
                        memo[cur] = 1;
                        break;
                    }
                }
            }
        }
        return memo[0];
    }
};


int main(void){
    string s = "dogandog";
    vector<string> wordDict = {"apple", "pen","cats", "dog", "sand", "and", "cat"};
    int value;
    Solution ss;
    value = ss.wordBreak(s,wordDict);
    cout<<value<<endl;
    return 0;
}