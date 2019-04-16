#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    string simplifyPath(string p) {
        vector<string> stack;
        int len = p.length();
        int cur = 1;
        int firstSlash = 0, endSlash = 0;
        while(cur<len){
            if(p[cur]=='/'){
                endSlash = cur;
                string newStr(p,firstSlash+1,endSlash-firstSlash-1);
                if(endSlash-firstSlash==1){
                }
                else if(newStr=="."){
                }
                else if(newStr==".."){
                    if(stack.size()){
                        stack.pop_back();
                    }
                }
                else{
                    stack.push_back(newStr);
                }
                firstSlash = endSlash;
            }
            ++cur;
        }
        if(p[len-1]!='/'){
            string newStr(p,firstSlash+1,len-firstSlash-1);
            if(endSlash-firstSlash==1){
                ++cur;
            }
            else if(newStr=="."){
            }
            else if(newStr==".."){
                if(stack.size()){
                    stack.pop_back();
                }
            }
            else{
                stack.push_back(newStr);
            }
        }
        string newStr;
        newStr.append(1,'/');
        if(stack.size()>=1){
            for(int i = 0;i<stack.size()-1;++i){
                newStr.append(stack[i]);
                newStr.append(1,'/');
            }
            newStr.append(stack[stack.size()-1]);
        }
        return newStr;
    }
};



int main(void){
    string ss = "/a//b////c/d//././/..";
    Solution s;
    string t;
    t = s.simplifyPath(ss);
    cout<<t<<endl;


    return 0;
}