class CustomStack {
public:
    stack<int> st;
    int size,count=0;
    CustomStack(int maxSize) {
        size=maxSize;
    }
    
    void push(int x) {
        if(count<size){
            st.push(x);
            count++;
        }
    }
    
    int pop() {
        if(!st.empty()){
            int temp=st.top();
            st.pop();
            count--;
            return temp;
        } 
        return -1;
        
    }
    
    void increment(int k, int val) {
        stack<int> temp;
        int i=0;
        while(!st.empty()){
            temp.push(st.top());
            st.pop();
        }
        while(i<k && !temp.empty()){
            st.push(temp.top()+val);
            temp.pop();
            i++;
        }
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */