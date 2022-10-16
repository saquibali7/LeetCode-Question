class Solution {
public:
    int dp[301][11];
    int helper(vector<int> &jobDifficulty,int i,int d){
        if(d==0){
            int maxi=jobDifficulty[i];
            for(int k=i;k<jobDifficulty.size();k++){
                maxi=max(maxi,jobDifficulty[k]);
            }
            return dp[i][d]=maxi;
        }
        if(i==jobDifficulty.size()-1){
            if(d!=0)
                return dp[i][d]=300000;
            else
                return dp[i][d]=jobDifficulty[i];
        }
        if(dp[i][d]!=-1)
            return dp[i][d];

        int maxi=jobDifficulty[i];
        int ans=300000;
        for(int k=i+1;k<jobDifficulty.size();k++) {
            ans=min(ans,maxi+helper(jobDifficulty,k,d-1));
            maxi=max(maxi,jobDifficulty[k]);
        }

        return dp[i][d]=ans;
        
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(d>jobDifficulty.size()){
            return -1;
        }
        memset(dp,-1,sizeof(dp));
        return helper(jobDifficulty,0,d-1);

    }
};