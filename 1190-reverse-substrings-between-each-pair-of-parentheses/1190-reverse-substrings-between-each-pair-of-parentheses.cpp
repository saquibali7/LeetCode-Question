class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.length();
        stack<int> st;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i+1);
            } else if(s[i]==')'){
                int low=st.top(),high=i-1;
                while(low<high){
                    swap(s[low],s[high]);
                    low++;
                    high--;
                }
                st.pop();
                
            }
        }
        string temp="";
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                continue;
            } else if(s[i]==')'){
                continue;
            } else {
                temp+=s[i];
            }
        }
        return temp;
    }
};