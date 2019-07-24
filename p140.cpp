#include <vector>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string> strSet(wordDict.begin(),wordDict.end());
        int strlen = s.length();
        vector<vector<string>> result(strlen+1);
        vector<int> memo(strlen+1,0);
        memo[strlen] = 1;
        if(!canWordBreak(s,wordDict,strSet,memo)) return result[0];
        for(int start = strlen-1;start>=0;--start){
            if(memo[start]!=1)continue;
            for(int len = 1;len<=strlen-start;++len){
                if(memo[start+len]==1&&strSet.find(s.substr(start,len))!=strSet.end()){
                    if(result[start+len].size()==0) result[start].emplace_back(s.substr(start,len));
                    for(int i = 0;i<result[start+len].size();++i){
                        string temp = s.substr(start,len);
                        temp.append(" "+result[start+len][i]);
                        result[start].emplace_back(temp);
                    }
                }                
            }
        }
        return result[0];
    }
private:
    bool canWordBreak(string s, vector<string>& wordDict, set<string>& strSet, vector<int>& memo) {
        int strlen = s.length(), cur = strlen-1;
        if(strlen<=0) return 0;
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
