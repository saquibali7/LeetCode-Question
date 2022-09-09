class Solution {
public:
    bool isPalindrome(string s){
        int low=0,high=s.length()-1;
        while(low<high){
            if(s[low]!=s[high]){
                return false;
            }
            low++;
            high--;
        }
        return true;
    }
    bool isStrictlyPalindromic(int n) {
        int num = n;
        for(int i=2;i<=n-2;i++){
            string res="";
            int temp=n;
            while(temp > 0){
                int rem = temp/i;
                temp/=i;
                res+=to_string(rem);
            }
            if(!isPalindrome(res)){
                return false;
            }
        }
        return true;
    }
};