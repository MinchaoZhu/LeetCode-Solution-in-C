class Solution {
public:
    int calculate(string s) {
        vector<string> rev;
        stack<char> st;
        string str = "";
        for(int i = 0; i<s.length(); ++i) {
            if(s[i] != ' '){
                str += s[i];
            }
        }
        return cal(str);
    }
    
private:
    int cal(string s) {
        int result = 0;
        int flag = 1, len = s.length();
        int i = 0;
        while(i < len) {
            if(s[i] == '+')
                flag = 1;
            else if(s[i] == '-')
                flag = -1;
            else if(s[i] == '(') {
                int open = 1, j = i + 1;
                while(open >= 1) {
                    if(s[j] == '(')
                        ++open;
                    else if(s[j] == ')')
                        --open;
                    ++j;
                }
                
                result += flag * cal(s.substr(i + 1, j - i - 2));
                i = j - 1;
                
            }
            else {
                int j = i + 1;
                while(j < len && s[j]>='0' && s[j]<='9')
                    ++j;
                result += flag * stoi(s.substr(i, j - i));
                i = j - 1;
            }
            ++i;
        }
        return result;
    }
};