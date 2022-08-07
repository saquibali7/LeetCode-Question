class Solution {
public:
    int countVowelPermutation(int n) {
        long a=1,e=1,i=1,o=1,u=1;
        long a2,i2,e2,o2,u2;
        int mod = pow(10,9)+7;
        for(int j=2;j<=n;j++){
            a2 = (e+u+i)%mod;
            e2 = (a+i)%mod;
            i2 = (e+o)%mod;
            o2 = i%mod;
            u2 = (o+i)%mod;
            a=a2,e=e2,i=i2,o=o2,u=u2;
        }
        
        int res = (a+e+i+o+u)%mod;
        return res;
    }
};