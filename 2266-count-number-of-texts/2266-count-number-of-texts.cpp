class Solution {
public:
    int mod=pow(10,9)+7;
    long long countfre(int n,int v){
        vector<int long> dp(n+4);
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        dp[3]=4;
        dp[4]=8;
        if(v==3){
            for(int i=4;i<=n;i++){
                dp[i]=(dp[i-1]+dp[i-2]+dp[i-3])%mod;
            }
        } else {
            for(int i=5;i<=n;i++){
                dp[i]=(dp[i-1]+dp[i-2]+dp[i-3]+dp[i-4])%mod;
            }
        }
        return dp[n];
    }
    int countTexts(string s) {
        int n=s.length();
        int count=1;
        long long int res=1;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                count++;
            } else {
                if(s[i-1]=='7' || s[i-1]=='9'){
                    res*=countfre(count,4);
                } else {
                    res*=countfre(count,3);
                }
                count=1;
            }
            res = res%mod;
        }
        if(count> 1 && (s[n-1]=='7' || s[n-1]=='9')){
             res*=countfre(count,4);
        } else if(count>1){
            res*=countfre(count,3);
        }
        res = res%mod;
        return res;
    }
};