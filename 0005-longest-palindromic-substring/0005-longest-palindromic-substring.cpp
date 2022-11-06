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
    string longestPalindrome(string s) {
        int n=s.length();
        int l=0,r=0;
        for(int i=0;i<s.length();i++){
            int low = i-1,high=i+1;
            while(low>=0 && high<n && s[low]==s[high]){
                low--;
                high++;
            }
            high--;
            low++;
            if((high-low+1)>=(r-l+1)){
                l=low;
                r=high;
            }
        }
        for(int i=0;i<n-1;i++){
            int low=i,high=i+1;
            while(low>=0 && high<n && s[low]==s[high]){
                low--;
                high++;
            }
            high--;
            low++;
            if((high-low+1)>(r-l+1)){
                l=low;
                r=high;
            }
        }
        return s.substr(l,r-l+1);
        
    }
};