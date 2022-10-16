int dp[101][27][101][101];
class Solution {
public:
    string str;
    int helper(int i, int prev, int len, int k){
        if(k<0){
            return INT_MAX;
        }
        if(i>=str.size()){
            return 0;
        }
        if(dp[i][prev][len][k]!=-1){
            return dp[i][prev][len][k];
        }
        int del = helper(i+1,prev, len,k-1);
        int keep=0;
        if(str[i]-'a' == prev){
            if(len==1 || len==9 || len==99){
                keep+=1;
            } 
            keep = keep + helper(i+1,prev, len+1,k);
        } else {
            keep = 1+helper(i+1,str[i]-'a',1,k);
        }
        dp[i][prev][len][k]=min(del,keep);
        return dp[i][prev][len][k];
            
    }
    int getLengthOfOptimalCompression(string s, int k) {
        str=s;
        memset(dp, -1, sizeof(dp));
        return helper(0,26,0,k);
        
    }
};