class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        int n=s.length();
        st.push(s[0]);
        for(int i=1;i<n;i++){
            if(!st.empty() && s[i]+32 == st.top()){
                st.pop();
                continue;
            } else if(!st.empty() && s[i] == st.top()+32){
                st.pop();
                continue;
            }
            st.push(s[i]);
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};