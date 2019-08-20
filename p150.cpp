#include <stack>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int size = tokens.size();
        int result;
        for(int i = 0; i<size;++i){
            if((tokens[i].compare("+"))&&(tokens[i].compare("-"))&&(tokens[i].compare("*"))&&(tokens[i].compare("/"))){
                st.push(stoi(tokens[i]));
            }
            else{
                int a = st.top(),b;
                st.pop();
                b = st.top();
                st.pop();
                st.push(cal(a,b,tokens[i]));
            }


        }
        return st.top();
    }
private:
    int cal(const int& a, const int& b, const string& oper){
        // aa is the first number poped from stack, and bb's second one
        if(oper=="+")      return b+a;
        else if(oper=="-") return b-a;
        else if(oper=="*") return b*a;
        else if(oper=="/") return b/a;
        else return 0;
    }

};

