class Solution {
public:
    int maximum69Number (int num) {
        stack<int> st;
        while(num > 0){
            int rem=num%10;
            st.push(rem);
            num /=10;
        }
        int res=0;
        bool flag=false;
        while(st.empty()==false){
            if(st.top()==6 && !flag){
                flag=true;
                res = res*10 + 9;
            } else {
                res = res*10 + st.top();;
            }
            st.pop();
        }
        return res;
        
    }
};