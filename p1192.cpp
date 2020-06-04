class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> num(n, INT_MAX);
        vector<int> low(n, INT_MAX);
        vector<vector<int>> g(n, vector<int>());
        vector<vector<int>> result;
        for(int i = 0; i<connections.size(); ++i){
		// build graph by using adjacent table
            g[connections[i][0]].emplace_back(connections[i][1]);
            g[connections[i][1]].emplace_back(connections[i][0]);
        }
        int counter = 0; // number of verteces visited
        
        dfs(g, num, low, 0, counter, -1);
        
        for(int i = 0; i<connections.size(); ++i){
		// parent U -> child V
		// low[V] > num[U] => valid critical connection
            int v1 = connections[i][0], v2 = connections[i][1];
            if((num[v1]<num[v2]&&low[v2]>num[v1])||(num[v1]>num[v2]&&low[v1]>num[v2])){
                result.emplace_back(vector<int>{v1, v2});
            }
        }
        
        return result;
    }
    
private:
	/**
	* This method do a dfs and will return the minimum LOW through the path then backtracking to the previous vertex
	*/
    int dfs(vector<vector<int>>& g, vector<int>& num, vector<int>& low, int vertex, int& counter, int parent){
        if(num[vertex] == INT_MAX){
		// if this vertex hasn't been visited
            num[vertex] = counter;
            low[vertex] = counter;
            int minTmp = counter;
            ++counter;
            
            for(int i = 0; i<g[vertex].size(); ++i){
			// continue visiting
                if(g[vertex][i] != parent){
                    int tmp = dfs(g, num, low, g[vertex][i], counter,vertex);
                    minTmp = min(minTmp, tmp);
                }
            }
            low[vertex] = minTmp;
            return minTmp;
        }
        else{
            return low[vertex];
        }
    }
    
};