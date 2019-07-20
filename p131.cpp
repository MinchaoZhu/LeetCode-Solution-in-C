#include <vector>
#include <stdbool.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> temp;
        if(s.empty()) return result;
        dfs(result,temp,s,0);
        return result;
    }

private:

    void dfs(vector<vector<string>>& result, vector<string>& temp, string& s, int index){
        if(index == s.length())
            result.emplace_back(temp);
        else{
            for(int len = 1; len<s.length()-index+1;++len){
                if(isPalindrome(s,index,index+len-1)){
                    temp.emplace_back(s.substr(index,len));
                    dfs(result,temp,s,index+len);
                    temp.pop_back();
                }

            }
        }
    }

    bool isPalindrome(const string& s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
};

int main(void){
    Solution s;
    string ss = "aab";
    vector<vector<string>> result;
    result = s.partition(ss);
}