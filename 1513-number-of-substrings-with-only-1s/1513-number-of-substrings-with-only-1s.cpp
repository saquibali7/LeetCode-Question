class Solution {
public:
    int numSub(string s) {
        int n=s.length();
        long long int count=0,res=0,mod=pow(10,9)+7;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                count++;
            } else {
                if(count){
                    res+=((count+1)*(count))/2;
                    count=0;
                }
            }
        }
        if(count){
            res+=((count+1)*(count))/2;
        }
        res = res%mod;
        return res;
    }
};