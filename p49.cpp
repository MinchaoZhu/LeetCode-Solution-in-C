#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        int size = strs.size(),i=1;
        bool cap[size] = {0};
        if(size>=1){
            vector<string> *newStrVec = new vector<string> ;
            newStrVec->push_back(strs[0]);
            result.push_back(*newStrVec);
            for(;i<size;++i){
                bool isA = 0;
                for(int j=0;j<result.size();++j){
                    if(isAnagrams(strs[i],result[j][0])){
                        result[j].push_back(strs[i]);
                        isA = 1;
                    }
                }
                if(!isA){
                    vector<string> *newStrVec = new vector<string> ;
                    newStrVec->push_back(strs[i]);
                    result.push_back(*newStrVec);
                    DONE: ;
                }
            }
        }
        return result;
    }

private:
    bool isAnagrams(string& s1, string& s2){
        int l1 = s1.length(), l2 = s2.length();
        if(l1!=l2)
            return 0;
        int map[26] = {0};
        for(int i = 0;i<l1;++i){
            ++map[s1[i]-'a'];
        }
        for(int i = 0;i<l2;++i){
            --map[s2[i]-'a'];
        }
        for(int i = 0;i<26;++i){
            if(map[i])
                return 0;
        }
        return 1;
    }
};


int main(void){



    return 0;
}