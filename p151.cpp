#include <vector>
#include <string>
#include <iostream>
using namespace std;


class Solution {
public:
    string reverseWords(string s) {
        string result;
        int end = s.length()-1;
        for(int i = s.length()-1;i>=0;--i){
            if(s[i]==' '){
                if(end!=i){ 
                    result.append(s.substr(i+1,end-i));
                    if(i>=0) result.push_back(' ');
                }
                end = i-1;
            }
        }
        result.append(s.substr(0,end+1));
        if(result[result.size()-1]==' ') result.erase(result.end()-1);
        return result;
    }
};



int main(void){
    Solution s;
    string ss = "   a  good exam   ";
    string n;

    n = s.reverseWords(ss);
    cout<<n<<endl;



}