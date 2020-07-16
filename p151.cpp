#include <vector>
#include <string>
#include <iostream>
using namespace std;



// class Solution {
// public:
//     string reverseWords(string s) {
//         vector<string> v = split(s, " ");
//         if(v.size() <= 0) return "";
            
//         string result = v[v.size()-1];
//         for(int i = v.size() - 2; i >=0; --i) {
//             result = result + " " + v[i];
//         }
//         return result;
//     }

// private:
//     std::vector<std::string> split(std::string str,std::string sep){
//         char* cstr=const_cast<char*>(str.c_str());
//         char* current;
//         std::vector<std::string> arr;
//         current=strtok(cstr,sep.c_str());
//         while(current!=NULL){
//             arr.push_back(current);
//             current=strtok(NULL,sep.c_str());
//         }
//         return arr;
//     }
    
// };

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