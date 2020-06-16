class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open = 0;
        string result = ""; 
        for(auto c : s){
            result += c;
            
            if(c == ')' && open <= 0){
                result.pop_back(); // if not balanced, remove last ')'
                ++ open;
            }
            
            open += c == '(' ? 1 : 0;
            open += c == ')' ? -1 : 0;
        }
        
		// from end to begin, remove  needless '('
        for(int i = result.length() - 1; open>0&&i>=0; --i){
            if(result[i] == '('){ 
                result.erase(i, 1);
                -- open;
            }
        }
        
        return result;
    }
};