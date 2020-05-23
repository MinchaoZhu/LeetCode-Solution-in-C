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


// DFS
// class Solution {
// public:
//     vector<string> wordBreak(string s, vector<string>& wordDict) {
//         if(s.length()>0&&canBeBreaked(s, wordDict)){
//             vector<string> result;
//             vector<vector<bool>> mem(s.length(), vector<bool>());
//             string tmp = "";
//             set<string> dict;
//             dict.insert(wordDict.begin(), wordDict.end());
//             for(int i = 0; i<s.length(); ++i){
//                 mem[i].resize(s.length());
//             }
//             dfs(result, dict, mem, tmp, s, 0);
//             return result;
//         }
//         else return vector<string>();
//     }

// private:
//     void dfs(vector<string>& result, set<string>& dict, vector<vector<bool>>& mem, string tmp, string& s, int start){
//         if(start == s.length()){
//             result.emplace_back(tmp.substr(0, tmp.length()-1));
//         }
//         else{
//             for(int i = start; i<s.length(); ++i){
//                 string str = tmp;
//                 if(mem[start][i]||dict.find(s.substr(start, i-start+1))!=dict.end()){
//                     str = str + s.substr(start, i-start+1) + " ";
//                     mem[start][i] = true;
//                     dfs(result, dict, mem, str, s, i+1);
//                 }
//             }    
//         }
//     }
                                    
//     bool canBeBreaked(string s, vector<string>& wordDict) {
//         if(s.length()>0){
//             bool dp[s.length()];
//             set<string> strs;
//             strs.insert(wordDict.begin(), wordDict.end());
//             dp[0] = strs.find(s.substr(0, 1))!=strs.end();

//             for(int i = 1; i<s.length(); ++i){
//                 dp[i] = strs.find(s.substr(0, i+1))!=strs.end();
//                 for(int j = i; j>0; --j){
//                     if(strs.find(s.substr(j, i-j+1))!=strs.end() && dp[j-1]){
//                         dp[i] = true;
//                         break;
//                     }
//                 }
//             }
//             return dp[s.length()-1];
//         }
//         else return 0;
//     }
// };