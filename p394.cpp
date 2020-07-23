class Solution {
public:
    string decodeString(string s) {
        if(s.length() > 0){
            int i = 0;
            string ret = "";
            while(i < s.length()) {
                if(s[i]>='0' && s[i]<='9') {
                    int j = i + 1;
                    while(s[j]>='0' && s[j]<='9')
                        ++j;
                    int repeat = stoi(s.substr(i, j - i));
                    int k = j+1, open = -1;
                    while(open<0) {
                        if(s[k] == '[')
                            --open;
                        else if(s[k] == ']')
                            ++open;
                        ++k;
                    }
                    string tmp = decodeString(s.substr(j+1, k-j-2));
                    for(int z = 0; z<repeat; ++z)
                        ret += tmp;
                    i = k;
                }
                else{
                    ret.push_back(s[i]);
                    ++i;
                }
            }
            return ret;
            
        }
        else return "";
    }
};