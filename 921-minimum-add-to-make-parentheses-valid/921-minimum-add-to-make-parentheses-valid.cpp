class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.length();
        stack<char> st;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(s[i]);
            } else if(s[i]==')' && st.empty()==false && st.top()=='('){
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
        return st.size();
        
    }
};