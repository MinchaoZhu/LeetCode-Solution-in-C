#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
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
        return max;
    }
};


int main(void){
    vector<int> h = {4,2,0,3,2,5};
    Solution s;
    int max;
    max = s.largestRectangleArea(h);
    cout<<max<<endl;
    return 0;
}