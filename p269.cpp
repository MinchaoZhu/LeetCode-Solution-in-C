#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string alienOrder(vector<string>& words) {
        int size = words.size();
        vector<vector<int>> g(128, vector<int>(128, 0));
        vector<int> in(128, -1);
        
        for(int i = 0; i< size - 1; ++i){
            auto e = orderGen(words[i], words[i+1]);
            if(e.first == '0'){
                continue;
            }
            if(e.first == '1'){
                return "";
            }
            if(g[e.first][e.second] != 1){
                g[e.first][e.second] = 1;
                in[e.first] += in[e.first] == -1?1:0;
                in[e.second] += in[e.second] == -1?2:1;
            }
        }
        
        string result = "";
        
        char next = findZeroInDegree(in);
        while(next != '0'){
            result += next;
            in[next] = -1;
            for(int i = 'a'; i<='z'; ++i){
                if(g[next][i] == 1){
                    -- in[i];
                }class Solution {
public:
    string alienOrder(vector<string>& words) {
        int size = words.size();
        
        if(size == 0)
            return "";
        if(size == 1)
            return words[0];
        
        vector<vector<int>> g(128, vector<int>(128, 0));
        vector<int> in(128, -1);
        
        
        for(int i = 0; i< size - 1; ++i){
            for(auto c : words[i]){ 
                in[c] += in[c] == -1?1:0;
            }
            for(auto c : words[i+1]){ 
                in[c] += in[c] == -1?1:0;
            }
            
            auto e = orderGen(words[i], words[i+1]);
            if(e.first == '0'){
                continue;
            }
            if(e.first == '1'){
                return "";
            }
            if(g[e.first][e.second] != 1){
                g[e.first][e.second] = 1;
                in[e.first] += in[e.first] == -1?1:0;
                in[e.second] += in[e.second] == -1?2:1;
            }
        }
        
        string result = "";
        
        char next = findZeroInDegree(in);
        while(next != '0'){
            result += next;
            in[next] = -1;
            for(int i = 'a'; i<='z'; ++i){
                if(g[next][i] == 1){
                    -- in[i];
                }
            }
            next = findZeroInDegree(in);
        }
        
        for(int i = 'a'; i<='z'; ++i){
            if(in[i] != -1){
                return "";
            }
        }
        
        return result;
        
        
        
        
    }
    
    
private:
    pair<char,char> orderGen(string s1, string s2){
        int i = 0;
        while(i<s1.length()&&i<s2.length()&&s1[i]==s2[i]){
            ++i;
        }
        if(i == s1.length()){
            return pair<char, char>('0', '0');
        }
        if(i == s2.length()){
            return pair<char, char>('1', '1');
        }
        
        return pair<char, char>(s1[i], s2[i]);
        
    }
    
    char findZeroInDegree(vector<int> in){
        for(int i = 'a'; i<='z'; ++i){
            if(in[i] == 0){
                return i;
            }
        }
        
        return '0';
    }
    
};



int main(void){
    vector<string> v = {"wrt","wrf","er","ett","rftt"};
    Solution s;
    cout<<s.alienOrder(v)<<endl;

    return 0;
}