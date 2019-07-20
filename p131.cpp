#include <vector>
#include <stdbool.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        int len = s.length();
        vector<vector<vector<string>>> result(len+1);
        if(s.length()!=0){
            vector<vector<string>> temp = {{s.substr(len-1,1)}};
            result[len-1] = temp;
            temp = {{}};
            result[len] = temp;
            for(int i = len-2;i>=0;--i){
                vector<vector<string>> temp0;
                for(int j = 1;j<len-i+1;++j ){
                    if(isPalindrome(s.substr(i,j))){
                        for(int k = 0;k<result[i+j].size();++k){
                            vector<string> vec = {s.substr(i,j)};
                            vec.insert(vec.end(),result[i+j][k].begin(),result[i+j][k].end());
                            temp0.emplace_back(vec);
                        }
                    }
                }
                result[i] = temp0;
            }
            return result[0];
        }
        else{
            vector<vector<string>> t{{}};
            return t;
        }
    }

private:
    bool isPalindrome(string s){
        int i = 0, j = s.length()-1;
        while(i<j){
            if(s[i]!=s[j])
                return 0;
            ++i,--j;
        }
        return 1;
    }
};

int main(void){
    Solution s;
    string ss = "aab";
    vector<vector<string>> result;
    result = s.partition(ss);
}