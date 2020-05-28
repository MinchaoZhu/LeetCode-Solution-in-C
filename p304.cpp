class NumMatrix {
private:
    vector<vector<int>> cul;
    
public:
    NumMatrix(vector<vector<int>>& matrix) {
    cul = vector<vector<int>>(matrix);
        int rows = matrix.size(), cols;
        if(rows>0){
             cols = matrix[0].size();
             if(cols>0){
                 for(int j = 1; j<cols; ++j){
                     cul[0][j] += cul[0][j-1];
                 }
                 for(int i = 1; i<rows; ++i){
                     cul[i][0] += cul[i-1][0];
                 }
                 for(int i = 1; i<rows; ++i){
                     for(int j = 1; j<cols; ++j){
                         cul[i][j] += cul[i-1][j] + cul[i][j-1] - cul[i-1][j-1];
                     }
                 }
             }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(cul.size()>0&&cul[0].size()>0){
            if(row1>row2||col1>col2){
                return 0;
            }
            if(row1==0&&col1==0){
                return cul[row2][col2];
            }
            else if(row1==0){
                return cul[row2][col2]-cul[row2][col1-1];
            }
            else if(col1==0){
                return cul[row2][col2]-cul[row1-1][col2];
            }
            else{
                return cul[row2][col2]-cul[row2][col1-1]-cul[row1-1][col2]+cul[row1-1][col1-1];
            }
        }
        return 0;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */