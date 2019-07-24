#include <vector>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string> strSet(wordDict.begin(),wordDict.end());
        vector<string> result;
        string temp;
        dfs(result,s,temp,strSet,0);
        return result;
    }

private:
    void dfs(vector<string>& result, string& s, string& temp, set<string>& strSet, int start){
        if(start>=s.length()){
            temp.erase(temp.end()-1);
            result.emplace_back(temp);
            temp.append(" ");
        }
        for(int len = 1;len<s.length()-start+1;++len){
            string subStr = s.substr(start,len);
            if(strSet.find(subStr)!=strSet.end()){
                temp.append(subStr+" ");
                dfs(result,s,temp,strSet,start+len);
                temp.erase(temp.end()-len-1,temp.end());
            }
        }
    }
};
