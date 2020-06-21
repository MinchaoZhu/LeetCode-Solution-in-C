class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> rank;
        int len = order.length();
        for(int i = 0; i<len; ++i){
            rank[order[i]] = i;
        }
        int size = words.size();
        for(int i = 0; i < size-1; ++i){
            auto p = compare(words[i], words[i+1]);
            if(p.first == 2 || (p.first!=2&&rank[p.first] > rank[p.second]))
			// if the confirmed real order contradicts dictionary
                return false;
        }
        
        return true;
    }
    
private:
    // this method compare two strings, and return two character whoes relative order can be confirmed by them.
	// if no order can be confirmed, such as "ab" and "ab" or "a" and "ab", return (1,1)
	// if such order is absolutely wrong, such as "ab" and "a", return (2,2)
    pair<char, char> compare(string s1, string s2 ){
        if(s1.compare(s2) == 0){
            return pair<char, char>(1, 1);
        }
        
        int len1 = s1.length(), len2 = s2.length();
        int i = 0;
        while(i<len1&&i<len2&&s1[i] == s2[i]){
            ++i;
        }
        
        if(i == len1){
            return pair<char, char>(1, 1);
        }
        if(i == len2){
            return pair<char, char>(2, 2);
        }
        return pair<char, char>(s1[i], s2[i]);
        
    }
    
};