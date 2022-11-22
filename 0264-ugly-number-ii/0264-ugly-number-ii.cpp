class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<int,vector<int>,greater<int>> pq;
        vector<int> dp(n+1);
        dp[0]=0;
        dp[1]=1;
        int i=1,j=1,k=1;
        for(int p=2;p<=n;p++){
            dp[p]=min(2*dp[i],min(3*dp[j],5*dp[k]));
            if(2*dp[i]==dp[p]){
                i++;
            }
            if(3*dp[j]==dp[p]){
                j++;
            }
            if(5*dp[k]==dp[p]){
                k++;
            }
        }
        return dp[n];
    }
};