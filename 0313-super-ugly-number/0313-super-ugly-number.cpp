class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<long long> dp(n+1,0);
        dp[1]=1;
        int m=primes.size();
        vector<pair<int,int>> temp;
        for(int i=0;i<m;i++){
            temp.push_back({primes[i],1});
        }
        for(int p=2;p<=n;p++){
            dp[p]=temp[0].first*dp[temp[0].second];
            for(int j=1;j<m;j++){
                dp[p]=min(dp[p],temp[j].first*dp[temp[j].second]);
            }
            for(int j=0;j<m;j++){
                if(dp[p]==temp[j].first*dp[temp[j].second]){
                    temp[j].second=temp[j].second+1;
                }
            }
        }
        return dp[n];
    }
};