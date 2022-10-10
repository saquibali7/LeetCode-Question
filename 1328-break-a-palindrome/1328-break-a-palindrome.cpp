class Solution {
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
public:
    string breakPalindrome(string palindrome) {
        int n=palindrome.length();
        if(n==1){
            return "";
        }
        unordered_map<char, int> m;
        for(auto i : palindrome){
            m[i]++;
        }
        if(m['a']==n || m['a']==n-1){
            palindrome[n-1]='b';
            return palindrome;
        }
        string temp,res;
        int idx = -1,v;
        bool flag=false;
        int low=0,high=n-1;
        for(int i=0;i<26;i++){
            int low=0,high=n-1;
            while(low<high){
                if(palindrome[low]!=97+i){
                    idx = low;
                    v=97+i;
                    break;
                }
                low++;
                high--;
            }
            for(int j=0;j<n;j++){
                if(j==idx){
                    temp+=(v);
                } else {
                    temp+=palindrome[j];
                }
            }
            if(isPalindrome(temp)){
                temp="";
            } else {
                break;
            }
        }
        
        return temp;
    }
};