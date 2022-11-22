class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        vector<int> temp;
        int count=1;
        while(count*count<=n){
            temp.push_back(count*count);
            count++;
        }
        dp[0]=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<temp.size();j++){
                if(temp[j]<=i){
                    int temp1 = dp[i-temp[j]];
                    if(temp1!=INT_MAX){
                        dp[i]=min(temp1+1,dp[i]);
                    }
                }
            }
        }
        return dp[n];
    }
};