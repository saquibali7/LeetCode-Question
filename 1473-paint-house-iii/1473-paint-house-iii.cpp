class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        const int INF = 1e9;
        vector<vector<int>> dp(target + 1, vector<int> (n, INF));
        if (houses[0] == 0) {
            dp[1] = cost[0];
        } 
        else {
            dp[1][houses[0] - 1] = 0;
        }
        for (int i = 1; i < m; i++) {
            for (int j = target; j > 0; j--) {
                for (int k = 0; k < n; k++) {
                    int minCost = dp[j][k];
                    dp[j][k] = INF;
                    if (houses[i] != 0 && houses[i] != k + 1) continue;
                    int c;
                    if(houses[i] == 0){
                        c=cost[i][k];
                    } else {
                        c=0;
                    }
                    minCost += c;
                    for (int p = 0; p < n; p++) {
                        if (k == p) continue;
                        minCost = min(minCost, dp[j - 1][p] + c);
                    }
                    dp[j][k] = minCost;
                }
            }
        }
        
        int ans = INF;
        for (int color = 0; color < n; color++) {
            ans = min(ans, dp[target][color]);
        }
        return (ans < INF ? ans : -1);
    }
};