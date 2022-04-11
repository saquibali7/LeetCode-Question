class Solution {
public:
    bool validPalindrome(string s) {
        int n=s.length();
        int low=0,high=n-1;
        int idx1,idx2;
        bool flag=false;
        while(low<high){
            if(s[low]!=s[high]){
                flag=true;
                idx1=low;
                idx2=high;
                break;
            }
            low++;
            high--;
        }
        if(!flag){
            return true;
        }
        string temp1="";
        string temp2="";
        for(int i=0;i<n;i++){
            if(i!=idx1){
                temp1+=s[i];
            }
            if(i!=idx2){
                temp2+=s[i];
            }
        }
        low=0,high=temp1.size()-1;
        while(low<high){
            if(temp1[low]!=temp1[high]){
                flag=false;
                break;
            }
            low++;
            high--;
        }
        if(flag){
            return true;
        }
        low=0,high=temp1.size()-1;
        while(low<high){
            if(temp2[low]!=temp2[high]){
                return false;
            }
            low++;
            high--;
        }
        return true;
        
    }
};