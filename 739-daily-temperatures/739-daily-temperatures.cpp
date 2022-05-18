class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        vector<int> temp;
        vector<int> res;
        int n=temperatures.size();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top().first<= temperatures[i]){
                st.pop();
            }
            int temp1 = st.empty()?0:st.top().second;
            temp.push_back(temp1);
            st.push({temperatures[i],i});
        }
        reverse(temp.begin(),temp.end());
        for(int i=0;i<n;i++){
            if(temp[i]==0){
                res.push_back(0);
            }
            else {
                res.push_back(temp[i]-i);
            }
        }
        return res;
        
    }
};