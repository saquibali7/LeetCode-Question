class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> res;
        stack<string> st;
        st.push(words[0]);
        for(int i=1;i<words.size();i++){
            string temp1=st.top();
            string temp2 = words[i];
            sort(temp1.begin(),temp1.end());
            sort(temp2.begin(),temp2.end());
            if(temp1 == temp2){
                continue;
            }
            st.push(words[i]);
        }
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),  res.end());
        return res;
        
    }
};