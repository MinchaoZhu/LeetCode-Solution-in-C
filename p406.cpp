
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> result(people);
        
        auto cmp = [](vector<int> v1, vector<int> v2){
            if(v1[0] == v2[0]){
                return v1[1] < v2[1]; 
            }
            else return v1[0] > v2[0];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> heap(cmp, people);
        list<int> avai;
        for(int i = 0; i<people.size(); ++i){
            avai.emplace_back(i);
        }
        
        while(!heap.empty()){
            vector<int> tmp = heap.top();
            heap.pop();
            auto iter = avai.begin();
            advance(iter, tmp[1]);
            int index = *iter;
            result[index][0] = tmp[0];
            result[index][1] = tmp[1];
            avai.erase(iter);
        }
        
        
        return result;
        
    }
};