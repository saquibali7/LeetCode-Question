class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n=s.length();
        string res="";
        if(n<k){
           return res;
        }
        stack<pair<char,int>> st;
        for(int i=0;i<n;i++){
            if(st.empty() || st.top().first!=s[i]){
                st.push({s[i],1});
            }
            else {
                int temp=st.top().second;
                st.pop();
                st.push({s[i],temp+1});
            }
            if(st.top().second==k){
                st.pop();
            }
        }
        while(st.empty()==false){
            for(int i=0;i<st.top().second;i++){
                res+=st.top().first;
            }
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};