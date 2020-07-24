class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
        vector<bool> visited(g.size(), false);
        vector<vector<int>> result;
        vector<int> tmp;
        dfs(g, result, visited, tmp, 0, g.size()-1);
        return result;
    }
    
private:
    void dfs(vector<vector<int>>& g, vector<vector<int>>& result, vector<bool>& visited, vector<int>& tmp, int next, int target) {
        if(!visited[next]) {
            tmp.emplace_back(next);    
            visited[next] = true;
            if(next == target) {
                result.emplace_back(tmp);
            }
            else {
                for(auto v : g[next])
                    dfs(g, result, visited, tmp, v, target);
            }
            visited[next] = false;
            tmp.pop_back();
        }
    }
    
};