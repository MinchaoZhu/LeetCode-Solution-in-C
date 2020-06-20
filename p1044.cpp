#define SEED 233

class Solution {
public:
    string longestDupSubstring(string S) {
        int len = S.length();
        int low = 0, high = len-1, mid = low + (high - low)/2;
        string result = "";
        
        while(low <= high){
            mid = low + (high - low)/2;
            if(search(mid, S, result)){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        
        return result;
    }
    
private:
    bool search(int subLen, string& S, string& result){
        unordered_set<unsigned long long> seen;
        int len = S.length();
        
        unsigned long long h = 0;
        for(int i = 0; i<subLen; ++i){
            h = h * SEED + S[i];
        }
            
       seen.insert(h);
        
        unsigned long long exp = 1;
        for(int i = 1; i<= subLen; ++i){
            exp *= SEED;
        }
        
        for(int i = 1; i <= len - subLen; ++i){
            h = h * SEED - S[i-1] * exp + S[i + subLen - 1];           
			//compute h[s.substr(i, subLen)] from h[s.substr(i-1, subLen )] 
            
            if(seen.find(h)!= seen.end()){
                result = S.substr(i, subLen);
                return true;
            }
           seen.insert(h);
        }
        
        return false;
    }
    
};