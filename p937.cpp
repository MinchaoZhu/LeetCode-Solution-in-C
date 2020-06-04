class Solution {
public:
    static bool logCmp(const string& s1, const string& s2){
        string l1, l2;
        int i = 0, j = 0;
        while(s1[i] != ' '){
            ++i;
        }
        l1 = s1.substr(i+1, s1.length() - i);
        while(s2[j] != ' '){
            ++j;
        }
        l2 = s2.substr(j+1, s2.length() - i);
        if(l1 == l2){
            return s1.substr(0, i) < s2.substr(0, j);
        }
        else return l1 < l2;
    }
    
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> result;
        for(auto s : logs){
            if(isLetterLog(s)){
                result.emplace_back(s);
            }
        }
        std::sort(result.begin(), result.end(), logCmp);
        for(auto s : logs){
            if(!isLetterLog(s)){
                result.emplace_back(s);
            }
        }        
        
        return result;
    }

private:
    bool isLetterLog(string s){
        int i = 0;
        while(s[i] != ' '){
            ++i;
        }
        return s[i+1] > '9';
    }
    
};