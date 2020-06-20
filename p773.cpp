struct QNode {
    int pos;
    int steps;
    string s;
    QNode(int _pos, int _steps, string _s){
        pos = _pos;
        steps = _steps;
        s = _s;
    }
};

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int rows = board.size(), cols = board[0].size();
        string s = "";
        int posOfZero = 0;
        for(int i = 0; i<rows; ++i){
            for(int j = 0; j<cols; ++j){
                s.push_back(board[i][j] + '0');
                posOfZero += board[i][j] == 0?i * cols + j : 0;
            }
        }
        if(s.compare("123450") == 0){
            return 0;
        }
        
        unordered_map<string, int> visited;
        queue<QNode> q;
        q.push(QNode(posOfZero, 0, s));
        visited[s] = 0;
        BFS(q, visited);
        
        if(visited.find("123450") != visited.end()){
            return visited["123450"];
        }
        return -1;
        
    }
    

private:
    void BFS(queue<QNode>& q, unordered_map<string, int>& visited){
        vector<vector<int>> avai = {{1,3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
        while(!q.empty()){
            auto current = q.front();
            q.pop();
            string s = current.s;
            int steps = current.steps;
            int posOfZero = current.pos;
            for(auto nextPosOfZero : avai[posOfZero]){
                string next = string(s);
                next[posOfZero] = s[nextPosOfZero];
                next[nextPosOfZero] = '0';                        
                if(visited.find(next) == visited.end()){
                    q.push(QNode(nextPosOfZero, steps + 1, next));
                    visited[next] = steps + 1;
                }
                if(next.compare("123450") == 0)
                    return;
            }
        }
        
    }
    
};