class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int dp[n][n];
        for(int i=0;i<n;i++){
            dp[0][i]=grid[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int res=INT_MAX;
                for(int p=0;p<n;p++){
                    if(p!=j){
                        res = min(res,dp[i-1][p]);
                    }
                }
                dp[i][j]=grid[i][j]+res;
            }
        }
        int res=INT_MAX;
        for(int i=0;i<n;i++){
            res=min(res, dp[n-1][i]);
        }
        return res;
    }
};