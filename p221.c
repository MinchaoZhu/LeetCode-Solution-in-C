

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize){
    if(matrixSize>0){
        int rows = matrixSize;
        int cols = *matrixColSize;
        if(cols>0){
            int result = 0;
            int dp[rows][cols];
            dp[0][0] = result = matrix[0][0]=='1';
            for(int i = 1; i < rows; ++i){
                dp[i][0] = matrix[i][0] == '1';
                result = (result  == 0)?(matrix[i][0] == '1'):1;
            }
            for(int j = 1; j < cols; ++j){
                dp[0][j] = matrix[0][j] == '1';
                result = (result  == 0)?(matrix[0][j] == '1'):1;
            }
            for(int i = 1; i < rows; ++i){
                for(int j = 1; j < cols; ++j){
                    if(matrix[i][j] == '0'){
                        dp[i][j] = 0;
                    }
                    else{
                        int l1 = 0, l2 = 0;
                        int max = dp[i-1][j-1];
                        for(int ii = 1; ii <= max; ++ii){
                            if(matrix[i-ii][j]=='0'){
                                break;
                            }
                            l1 = ii;
                        }
                        for(int ii = 1; ii <= max; ++ii){
                            if(matrix[i][j-ii]=='0'){
                                break;
                            }
                            l2 = ii;
                        }
                        dp[i][j] = l1<l2?l1+1:l2+1;
                        
                        result = result>dp[i][j]?result:dp[i][j];
                        
                    }                    
                }
            }
            
            return result*result;
        }
        else return 0;
    }
    else return 0;
}