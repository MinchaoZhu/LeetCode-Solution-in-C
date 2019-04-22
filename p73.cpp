#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        bool col0 = 1;
        /**
         * every head of rows(matrix[0][j]) indicates whether this row should be all 0;
         * every head of cols(matrix[i][0]) indicates whether this col should be all 0;
         * matrix[0][0] indicates whether first row should be 0;
         * flag col0 indicates whether first col should be 0;
         * */ 
        int i, j;
        for(i = 0;i<rows;++i){
            if(!matrix[i][0]) col0=0;
            for(j = 1;j<cols;++j){
                if(!matrix[i][j]){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(j = 1;j<cols;++j){
            if(!matrix[0][j]){
                for(i = 1;i<rows;++i){
                    matrix[i][j] = 0;
                }
            }
        }
        for(i = 1;i<rows;++i){
            if(!matrix[i][0]){
                for(j = 1;j<cols;++j){
                    matrix[i][j] = 0;
                }
            }
        }
        if(!matrix[0][0]){
            for(j = 1;j<cols;++j){
                matrix[0][j] = 0;
            }
        }
        if(!col0){
            for(i = 0;i<rows;++i){
                matrix[i][0] = 0;
            }
        }

    }
};





int main(void){
    vector<vector<int>> m = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    Solution s;
    s.setZeroes(m);
    for(int i = 0;i<m.size();++i){
        for(int j = 0; j<m[0].size();++j){
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}