#include <iostream>
#include <vector>
#include <string>
#include <limits.h>
using namespace std;


class Solution {
public:
    string minWindow(string s, string t) {
        int count[128] = {0};
        int wcount[128] = {0};
        int letters = 0, formed = 0;
        for(auto c : t){
            if(count[c]==0){
                letters+=1;
                ++count[c];
            }
            else ++count[c];
        }

        int r = 0,l = 0,minLen = INT32_MAX,resultL = 0, resultR=0;
        while(r<s.length()){
            while(r<s.length()&&formed<letters){
                if(count[s[r]]!=0){
                    if(count[s[r]]-wcount[s[r]]==1){
                        ++wcount[s[r]];
                        formed+=1;
                    }
                    else{
                        ++wcount[s[r]];
                    }
                }
                ++r;
            }

            while(l<r&&count[s[l]]==0||formed==letters){
                if(count[s[l]]!=0){
                    if(r-l<minLen){
                        resultL = l;
                        resultR = r;
                        minLen = r-l;
                    }
                    --wcount[s[l]];
                    if(wcount[s[l]]<count[s[l]]){
                        --formed;
                    }
                }
                ++l;
            }
        }
        return s.substr(resultL,resultR-resultL);
    }
};

int main(void){
    string s = "a";
    string t = "a";
    Solution ss;
    string nnn;
    nnn = ss.minWindow(s,t);
    cout<<nnn<<endl;

    return 0;
}