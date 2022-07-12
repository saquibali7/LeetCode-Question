class MinStack {
public:
    stack<int> st;
    stack<int> s;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(s.empty() || val<=s.top()){
            s.push(val);
        }
    }
    
    void pop() {
        if(s.top()==st.top()){
            st.pop();
            s.pop();
        } else {
            st.pop();
        }
    }
    
    int top() {
        return st.empty()?-1:st.top();
    }
    
    int getMin() {
        return s.empty()?-1:s.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */