#include <iostream>
#include <vector>
#include <string>
using namespace std;



class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> letters = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> result;
        if(digits.length()==0)return result;
        string temp;
        dfs(result,letters,digits,0,temp);
        return result;
    }

private: 
    void dfs(vector<string>& result, vector<string>& letters, string digits, int t, string& temp){
        int size = digits.length();
        if(t<size){
            int l = letters[digits[t]-'0'-2].length(),i = 0;
            for(i = 0;i<l;++i){
                temp.push_back(letters[digits[t]-'0'-2][i]);
                dfs(result,letters,digits,t+1,temp);
                temp.pop_back();
            }
        }
        else{
            result.push_back(temp);
        }
    }
};


int main(void){





    return 0;
}