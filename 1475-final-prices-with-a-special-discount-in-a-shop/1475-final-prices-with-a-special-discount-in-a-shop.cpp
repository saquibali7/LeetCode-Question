class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        stack<int> st;
        vector<int> res;
        if(n==0){
            return res;
        }
        res.push_back(prices[n-1]);
        st.push(prices[n-1]);
        for(int i=n-2;i>=0;i--){
            while(st.empty()==false && st.top()>prices[i]){
                st.pop();
            }
            int temp = (st.empty())?0:st.top();
            res.push_back(prices[i]-temp);
            st.push(prices[i]);
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
};