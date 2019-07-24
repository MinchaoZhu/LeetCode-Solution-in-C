#include <vector>
#include <string>
#include <iostream>
using namespace std;

#define UNKOWN 0
#define POSITIVE 1
#define NEGTIVE 2

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> memo(s.length(),0);
        return wordBreakSub(s,wordDict,memo);
    }

private:
    bool wordBreakSub(string& s, vector<string>& wordDict, vector<int>& memo, int start){
        if(s.length()<start) return 1;
        if(memo[start]!=0) return memo[start];
        for(int len = 1;len<=s.length()-start;++len){
            if(inDict(s,start,len,wordDict)){
                if(wordBreakSub(s,wordDict,memo,start+len)){
                    memo[start] = POSITIVE;
                    return 1;
                }
            }
        }
        memo[start] = NEGTIVE;
        return 0;
    }

    bool inDict(string& s, int start, int len, vector<string>& wordDict){
        string subStr = s.substr(start,len);
        for(auto str : wordDict){
            if(str.compare(subStr)==0)
                return 1;
        }
        return 0;
    }
};


int main(void){
    string s = "catsandog";
    vector<string> wordDict = {"apple", "pen","cats", "dog", "sand", "and", "cat"};
    int value;
    Solution ss;
    value = ss.wordBreak(s,wordDict);
    cout<<value<<endl;
}