#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string temp;
        generate(result,temp,s,1);
        return result;
    }

private:
    void generate(vector<string>& result, string& temp, string s, int k){
        if(k==4){
            if(s.length()==0)result.push_back(temp);
            else return ;
        }
        else{
            string sStr;
            if(k>1)temp.append(1,'.');
            for(int i = 1;i<=3&&i<=s.length();++i){
                if(validNum(s.substr(0,i))){
                    temp.append(s.substr(0,i));
                    generate(result,temp,s.substr(i,s.length()-i),k+1);
                    temp.erase(temp.length()-i,i);
                }
            }
        }
    }

    bool validNum(string s){
        int n = 0;
        int i = 0;
        while(i<s.length()){
            n*=10;
            n+=s[i]-'0';
        }
        if(n>255)return 0;
        else return 1;
    }
};




int main(void){
    Solution s;
    //string ss = "25525511135";
    string ss = "123";
    vector<string> re;
    re = s.restoreIpAddresses(ss);
    for(int i = 0;i<re.size();++i){
        cout<<re[i]<<endl;
    }

    return 0;
}

