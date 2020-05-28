int f_min(int a, int b){
    return a<b?a:b;
}
//O(nk^2)
int minCostII(int** costs, int costsSize, int* costsColSize){
    if(costsSize>0){
        int n = costsSize, k = *costsColSize;
        if(n>0){
            int dp[n][k];
            for(int j = 0; j<k; ++j){
                dp[0][j] = costs[0][j];
            }
            for(int i = 1; i<n; ++i){
                for(int j = 0; j<k; ++j){
                    int min = INT_MAX;
                    for(int t = 1; t<k; ++t){
                        min = f_min(min, dp[i-1][(j+t)%k]);
                    }
                    dp[i][j] = costs[i][j] + min;
                }    
            }
            
            int result = INT_MAX;
            for(int j = 0; j<k; ++j){
                result = f_min(dp[n-1][j], result);
            }
            
            return result;
        }
        return 0;
    }
    else return 0;
}

// // DP O(nk)
// void updateMinimum(int* minArr, int size, int new, int newIndex){
//     if(minArr[2] > new){
//         minArr[2] = new;
//         minArr[3] = newIndex;
//     }    
//     if(minArr[0] > minArr[2]){
//         int tmp = minArr[0];
//         minArr[0] = minArr[2];
//         minArr[2] = tmp;
        
//         tmp = minArr[1];
//         minArr[1] = minArr[3];
//         minArr[3] = tmp;
//     }
// }

// int minCostII(int** costs, int costsSize, int* costsColSize){
//     if(costsSize>0){
//         int n = costsSize, k = *costsColSize;
//         if(n>0){
//             int dp[n][k];
            
//             // minimum, minimum index, second minimum, second minimum index
//             int minArr[4] = {INT_MAX, -1, INT_MAX, -1};
            
//             for(int j = 0; j<k; ++j){
//                 dp[0][j] = costs[0][j];
//                 updateMinimum(minArr, 4, costs[0][j], j);
//             }
            
//             for(int i = 1; i<n; ++i){
                
//                 for(int j = 0; j<k; ++j){
//                     if(j==minArr[1]){
//                         dp[i][j] = costs[i][j] + minArr[2];
//                     }
//                     else{
//                         dp[i][j] = costs[i][j] + minArr[0];
//                     }
//                 }
//                 minArr[0] = INT_MAX, minArr[2] = INT_MAX;
//                 for(int j = 0; j<k; ++j){
//                     updateMinimum(minArr, 4, dp[i][j], j);
//                 }
//             }
            
//             return minArr[0];
//         }
//         return 0;
//     }
//     else return 0;
// }