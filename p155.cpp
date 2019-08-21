#include <vector>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        cell temp = {x,x};
        temp.value = x;        
        if(!st.empty()) 
            temp.min = x<st.back().min?x:st.back().min;
        st.emplace_back(temp);
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        return st.back().value;
    }
    
    int getMin() {
        return st.back().min;
    }

private:
    struct cell{
        int value;
        int min;
    };
    vector<cell> st;
};