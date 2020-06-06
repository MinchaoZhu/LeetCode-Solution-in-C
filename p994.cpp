class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.size() > 0){
            if(grid[0].size() > 0){
                int rows = grid.size(), cols = grid[0].size();
                vector<vector<int>> t(rows, vector<int>(cols, INT_MAX));
                for(int i = 0; i<rows; ++i){
                    for(int j = 0; j<cols; ++j){
                        t[i][j] = grid[i][j]==2?0:INT_MAX;
                    }
                }
                
                for(int row = 0; row<rows; ++row){
                    for(int col = 0; col<cols; ++col){
                        if(grid[row][col] == 2){
                            dfs(grid, t, row, col, 0);
                        }
                    }
                }
                
                int tMax = 0; 
                for(int i = 0; i<rows; ++i){
                    for(int j = 0; j<cols; ++j){
                        if(grid[i][j] == 1){
                            tMax = max(tMax, t[i][j]);
                        }
                    }
                }
                
                return tMax==INT_MAX?-1:tMax;
            }
        }
        return 0;
    }
    
private:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& t, int row, int col, int time){
        if(time < t[row][col]){
            t[row][col] = time;
        }
        
        if(row-1>=0 && grid[row-1][col] == 1 && t[row-1][col] > time + 1){
            dfs(grid, t, row-1, col, time+1);
        }
        if(row+1<grid.size() && grid[row+1][col] == 1 && t[row+1][col] > time + 1){
            dfs(grid, t, row+1, col, time+1);
        }
        if(col-1>=0 && grid[row][col-1] == 1 &&t[row][col-1] > time + 1){
            dfs(grid, t, row, col-1, time+1);
        }
        if(col+1<grid[0].size() && grid[row][col+1] == 1 && t[row][col + 1] > time + 1){
            dfs(grid, t, row, col+1, time+1);
        }
        
    }
    
};


// class Solution {
// public:
//     int orangesRotting(vector<vector<int>>& grid) {
//         if(grid.size() > 0){
//             if(grid[0].size() > 0){
//                 int rows = grid.size(), cols = grid[0].size();
//                 vector<vector<int>> t(rows, vector<int>(cols, INT_MAX));
//                 for(int i = 0; i<rows; ++i){
//                     for(int j = 0; j<cols; ++j){
//                         t[i][j] = grid[i][j]==2?0:INT_MAX;
//                     }
//                 }
                
//                 for(int row = 0; row<rows; ++row){
//                     for(int col = 0; col<cols; ++col){
//                         if(grid[row][col] == 2){
//                             if(row-1>=0 && grid[row-1][col] == 1 && t[row-1][col] > 1){
//                                 dfs(grid, t, row-1, col, 1);
//                             }
//                             if(row+1<grid.size() && grid[row+1][col] == 1 && t[row+1][col] > 1){
//                                 dfs(grid, t, row+1, col, 1);
//                             }
//                             if(col-1>=0 && grid[row][col-1] == 1 &&t[row][col-1] > 1){
//                                 dfs(grid, t, row, col-1, 1);
//                             }
//                             if(col+1<grid[0].size() && grid[row][col+1] == 1 && t[row][col + 1] > 1){
//                                 dfs(grid, t, row, col+1, 1);
//                             }
//                         }
//                     }
//                 }
                
//                 int tMax = 0; 
//                 for(int i = 0; i<rows; ++i){
//                     for(int j = 0; j<cols; ++j){
//                         if(grid[i][j] == 1){
//                             tMax = max(tMax, t[i][j]);
//                         }
//                     }
//                 }
                
//                 return tMax==INT_MAX?-1:tMax;
//             }
//         }
//         return 0;
//     }
    
// private:
//     void dfs(vector<vector<int>>& grid, vector<vector<int>>& t, int row, int col, int time){
//         if(time < t[row][col]){
//             t[row][col] = time;
//         }
        
//         if(row-1>=0 && grid[row-1][col] == 1 && t[row-1][col] > time + 1){
//             dfs(grid, t, row-1, col, time+1);
//         }
//         if(row+1<grid.size() && grid[row+1][col] == 1 && t[row+1][col] > time + 1){
//             dfs(grid, t, row+1, col, time+1);
//         }
//         if(col-1>=0 && grid[row][col-1] == 1 &&t[row][col-1] > time + 1){
//             dfs(grid, t, row, col-1, time+1);
//         }
//         if(col+1<grid[0].size() && grid[row][col+1] == 1 && t[row][col + 1] > time + 1){
//             dfs(grid, t, row, col+1, time+1);
//         }
        
//     }
    
// };