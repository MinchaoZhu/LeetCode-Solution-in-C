//DFS
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()<1) return 0;
        int rows = grid.size(), cols = grid[0].size();
        int count = 0;
        
        for(int i = 0; i<rows; ++i){
            for(int j = 0; j<cols; ++j){
                if(grid[i][j] == '1'){
                    setIsland(grid, i, j);
                    count++;
                }
            }
        }
        
        return count;
    }
    
private:
    void setIsland(vector<vector<char>>& grid, int i, int j){
        int rows = grid.size(), cols = grid[0].size();
        grid[i][j] = '0';
        if(i-1>=0){
            if(grid[i-1][j] == '1'){
                setIsland(grid, i-1, j);
            }
        }        
        if(j-1>=0){
            if(grid[i][j-1] == '1'){
                setIsland(grid, i, j-1);
            }
        }
        
        if(i+1<rows){
            if(grid[i+1][j] == '1'){
                setIsland(grid, i+1, j);
            }
        }
        if(j+1<cols){
            if(grid[i][j+1] == '1'){
                setIsland(grid, i, j+1);
            }
        }
        
    }    
    
};

// Union and Find
// class UnionFind{
// private:
//     vector<int> root;

// public:
//     UnionFind(){
        
//     }
    
//     int insert(){
//         root.emplace_back(-1);
//         return root.size() - 1;
//     }
    
//     int find(int i){
//         if(root[i]>=0){
//             int r = find(root[i]);
//             root[i] = r;
//             return r;
//         }        
//         return i;
//     }
    
//     void connect(int i, int j){
//         if(find(i)!=find(j)){
//             root[i] += root[find(j)];
//             root[find(j)] = i;
//         }
//     }
    
//     int number(){
//         int count = 0;
//         for(auto i : root){
//             count += i<0?1:0;
//         }
//         return count;
//     }
    
// };


// class Solution {
// public:
//     int numIslands(vector<vector<char>>& grid) {
//         if(grid.size()!=0){
//             if(grid[0].size()!=0){
//                 int rows = grid.size(), cols = grid[0].size();
//                 int countZero = 0;
//                 UnionFind uf;
//                 for(int i = 0; i<rows;++i){
//                     for(int j = 0; j<cols; ++j){
//                         countZero += grid[i][j] == '0';
//                         uf.insert();
//                         if(grid[i][j] == '1'){
//                             if(i-1>=0&&grid[i-1][j] == '1'){
//                                 uf.connect(i*cols+j, (i-1)*cols+j);
//                             }
//                             if((j-1)>=0&&grid[i][j-1] == '1'){
//                                 uf.connect(i*cols+j, i*cols+j-1);
//                             }
                            
//                         }
                        
//                     }
//                 }
//                 return uf.number() - countZero;
//             }
//         }
        
//         return 0;
//     }
// };