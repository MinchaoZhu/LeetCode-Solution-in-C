#include <iostream>
#include <vector>
#include <stack>
using namespace std;


class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0)return 0;
        vector<int> h(matrix[0].size(),0);
        int max = 0;
        for(int row=0;row<matrix.size();++row){
            for(int col=0;col<matrix[0].size();++col){
                h[col] = matrix[row][col]=='0'?0:h[col]+1;
            }
            int s = largestRectangleArea(h);
            max = max>s?max:s;
        }
        return max;
    }

private:
    int largestRectangleArea(vector<int>& h) {
        h.push_back(0);
        stack<int> stk;
        int max=0;
        int i = 0;
        int s = 0;
        for(;i<h.size();++i){
            while(!stk.empty()&&h[i]<h[stk.top()]){
                int top = stk.top();
                stk.pop();
                s = stk.empty()?i*h[top]:(i-stk.top()-1)*h[top];
                max = max>s?max:s;
            }
            stk.push(i);
        }
        h.pop_back();
        return max;
    }

};



int main(void){
    vector<vector<char>> matrix = {{}
};

    Solution s;
    int max;
    max = s.maximalRectangle(matrix);
    cout<<max<<endl;



    return 0;
}