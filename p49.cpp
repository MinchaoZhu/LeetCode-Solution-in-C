#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string,vector<string>> map;
        string sortedS;
        for(string s: strs){
            sortedS = s;
            sort(sortedS.begin(),sortedS.end());
            map[sortedS].push_back(s);
        }
    
        vector<vector<string>> result;
        for(auto t = map.begin();t!=map.end();++t){
            result.push_back(t->second);
        }
        return result;
    }
};


int main(void){



    return 0;
}