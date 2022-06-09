class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        if(n==1){
            return triangle[0][0];
        }
        vector<vector<int>> dp;
        dp.push_back(triangle[0]);
        for(int i=1;i<n;i++){
            vector<int> temp;
            temp.push_back(dp[i-1][0]+triangle[i][0]);
            int m=triangle[i].size();
            for(int j=1;j<m-1;j++){
                int temp2 = min(dp[i-1][j],dp[i-1][j-1])+triangle[i][j];
                temp.push_back(temp2);
            }
            temp.push_back(dp[i-1][m-2]+triangle[i][m-1]);
            dp.push_back(temp);
        }
        int res=INT_MAX;
        for(int i=0;i<dp[n-1].size();i++){
            res = min(res,dp[n-1][i]);
        }
        return res;
        
        
    }
};