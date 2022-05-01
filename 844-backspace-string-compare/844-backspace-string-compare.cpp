class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n=s.size(),m=t.size();
        stack<char> s1;
        stack<char> s2;
        for(int i=0;i<n;i++){
            if(s[i]=='#' && s1.empty()==false){
                s1.pop();
            } else if(s[i]!='#') {
                s1.push(s[i]);
            }
        }
        for(int i=0;i<m;i++){
            if(t[i]=='#' && s2.empty()==false){
                s2.pop();
            } else if(t[i]!='#') {
                s2.push(t[i]);
            }
        }
        if(s1.size()!=s2.size()){
            return false;
        }
        while(s1.empty()==false && s2.empty()==false){
            if(s1.top()!=s2.top()){
                return false;
            }
            s1.pop();
            s2.pop();
        }
        return true;
    }
};