#include <vector>
#include <string>
using namespace std;



class Solution {
public:
    int numDistinct(string s, string t) {
        int sLen = s.length(), tLen = t.length();
        int result=0;
        findSeq(s,t,result);
        return result;    
    }

private:
    void findSeq(string s, string t, int& result){
        if(t.length()==0)++result;
        else if(s.length()<t.length()) return;
        else{
            for(int i=0;i<s.length();++i){
                if(s[i]==t[0]){
                    findSeq(s.substr(i+1,s.length()-i-1),t.substr(1,s.length()-1),result);
                }
            }
        }
    }
};