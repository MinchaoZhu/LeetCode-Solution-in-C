#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <string.h>

using namespace std;


// class Solution {
// public:
//     int maximalRectangle(vector<vector<char>>& matrix) {
//         if(matrix.size()==0)return 0;
//         vector<int> h(matrix[0].size(),0);
//         int max = 0;
//         for(int row=0;row<matrix.size();++row){
//             for(int col=0;col<matrix[0].size();++col){
//                 h[col] = matrix[row][col]=='0'?0:h[col]+1;
//             }
//             int s = largestRectangleArea(h);
//             max = max>s?max:s;
//         }
//         return max;
//     }

// private:
//     int largestRectangleArea(vector<int>& h) {
//         h.push_back(0);
//         stack<int> stk;
//         int max=0;
//         int i = 0;
//         int s = 0;
//         for(;i<h.size();++i){
//             while(!stk.empty()&&h[i]<h[stk.top()]){
//                 int top = stk.top();
//                 stk.pop();
//                 s = stk.empty()?i*h[top]:(i-stk.top()-1)*h[top];
//                 max = max>s?max:s;
//             }
//             stk.push(i);
//         }
//         h.pop_back();
//         return max;
//     }

// };

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m>0){
            int n = matrix[0].size();
            if(n>0){
                int maxRect = 0;
                int height[n];
                int left[n];
                int right[n];
                for(int i = 0; i<n;right[i++]=n-1);
                memset(height, 0, n*sizeof(int));
                memset(left, 0, n*sizeof(int));
                for(int i = 0; i<m; ++i){
                    int current_left = 0, current_right = n-1;
                    for(int j = 0; j<n; ++j){
                        if(matrix[i][j]=='1'){
                            left[j] = current_left>left[j]?current_left:left[j];
                            height[j] = height[j]+1;
                        }
                        else{
                            current_left = j + 1;
                            left[j] = 0;
                            height[j] = 0;
                        }
                    }
                    for(int j = n-1; j>=0; --j){
                        if(matrix[i][j]=='1'){
                            right[j] = current_right<right[j]?current_right:right[j];
                        }
                        else{
                            current_right = j-1;
                            right[j] = n-1;
                        }
                    }
                    for(int j = 0; j<n; ++j){
                        int area = height[j]*(right[j]-left[j]+1);
                        maxRect = maxRect>area?maxRect:area;
                    }
                }
                return maxRect;
            }
            else return 0;
        }
        else return 0;
    }
};





int main(void){
    vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};

    Solution s;
    int max;
    max = s.maximalRectangle(matrix);
    cout<<max<<endl;



    return 0;
}