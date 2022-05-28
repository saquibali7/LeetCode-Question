class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int dp[n+1];
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<=n-1;i++){
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        }
        dp[n]=min(dp[n-1],dp[n-2]);
        return dp[n];
        
    }
};