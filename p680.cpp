class Solution {
public:
    bool validPalindrome(string s) {
        int len = s.length();
        if(len == 0) return true;
        int left = 0, right = len - 1;
        
        while(left < right) {
            if(s[left] != s[right]) {
                return valid(s, left + 1, right) || valid(s, left, right - 1);
            }
            ++left, --right;
        }
        
        return true;
    }
    
private:
    bool valid(string s, int left, int right) {
        while(left < right) {
            if(s[left++] != s[right--]) {
                return false;
            }
        }
        
        return true;
    }
    
};
