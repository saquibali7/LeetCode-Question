class Solution {
public:
    string removeDuplicates(string s) {
        int n=s.length();
        string res="";
        if(n==0){
            res;
        }
        stack<char> st;
        st.push(s[0]);
        for(int i=1;i<n;i++){
            if(st.size() == 0){
                st.push(s[i]);
            }
            else if(st.top() == s[i] && st.size()>0){
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
        while(st.size() > 0){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
};