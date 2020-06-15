class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string tmp = "";
        
        dfs(result,tmp, 0, 0, n);
        
        return result;
    }
    
private:
    void dfs(vector<string>& result, string tmp, int l, int r, int n){
        // l: '(' in current tmp string
        // r: ')' in current tmp string
        if(r==n){
            result.emplace_back(tmp);
        }
        else{
            
            int len = tmp.length();
            if(l < n){
                tmp += "(";
                dfs( result, tmp, l+1, r, n );
                tmp.pop_back();   
            }
            if(r<l){
                tmp += ")";
                dfs( result, tmp, l, r+1, n);  
                tmp.pop_back();
            }
            
        }
    }
    
};