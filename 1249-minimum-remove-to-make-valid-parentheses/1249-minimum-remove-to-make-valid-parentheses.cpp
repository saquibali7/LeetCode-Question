class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.length();
        stack<pair<char,int>>st;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push({'(',i});
            } else if(st.empty()==false && s[i]==')' && st.top().first=='('){
                st.pop();
            } else if(s[i]==')'){
                st.push({')',i});
            } else {
                continue;
            }
        }
        string res="";
        for(int i=n-1;i>=0;i--){
            if(st.empty() == false && i==st.top().second){
                st.pop();
            } else {
                res+=s[i];
            }
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
};