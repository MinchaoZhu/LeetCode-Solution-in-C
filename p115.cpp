#include <vector>
#include <string>
#include <iostream>
using namespace std;



class Solution {
public:
    int numDistinct(string s, string t) {
        int sLen=s.length(),tLen = t.length();
        unsigned long table[tLen];for (int i = 0; i < tLen; i ++) table[i] = 0;
        for(int i=0;i<sLen;++i){
            for(int j=tLen-1;j>=0;--j){
                if(s[i]==t[j]){
                    if(j==0)++table[0];
                    else table[j]+=table[j-1];
                }
            }
        }
        return table[tLen-1];
    }
};




int main(void){
    string s = "rabbbit";
    string t = "rabbit";
    int i=0;
    Solution ss;
    i = ss.numDistinct(s,t);
    cout<<i<<endl;

    return 0;
}