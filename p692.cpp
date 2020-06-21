class Solution {
public:
    
    class Compare{
    public:
        bool operator()(pair<string,int> p1, pair<string,int> p2){
            if(p1.second == p2.second){
                return p1.first < p2.first;
            }
            
            return p1.second > p2.second;
        }
    };
    
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> freq;
        for(auto word:words){
            freq[word]++;
        }
        
        priority_queue<pair<string,int>, vector<pair<string,int>>, Compare> pq;
        
        for(auto val:freq){
            pq.push({val.first,val.second});
            if(pq.size() > k){
                pq.pop();
            }
        }
        
        vector<string> res;
        
        while(!pq.empty()){
            res.push_back(pq.top().first);
            pq.pop();
        }
        
        reverse(res.begin(),res.end());
        
        return res;
    }
};


// class Solution {
// public:
//     vector<string> topKFrequent(vector<string>& words, int k) {
//         unordered_map<string, pair<string, int>> s;
//         for(auto word : words){
//             if(s.find(word) == s.end()){
//                 s[word] = pair<string, int>(word, 0);
//             }
//             else{
//                 s[word].second += 1;
//             }
//         }
        
//         auto cmp = [](pair<string, int> p1, pair<string, int> p2){
//             if(p1.second == p2.second){
//                 return p1.first < p2.first;
//             }
//             else{
//                 return p1.second > p2.second;
//             }
            
//         };
//         priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp) > pq(cmp);
        
//         auto iter = s.begin();
//         for(int i = 0; i<k; ++i){
//             pq.push(iter->second);
//             ++iter;
//         }
        
//         while(iter != s.end()){
//             pq.push(iter->second);
//             pq.pop();
//             ++iter;
//         }
        
//         vector<string> result(k);
        
//         for(int i = k-1; i>=0; --i){
//             auto pair = pq.top();
//             pq.pop();
//             result[i] = pair.first;
//         }
        
        
//         return result;
        
//     }
// };