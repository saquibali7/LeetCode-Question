class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     int n=s.length();
     int res=0;
     for(int i=0;i<n;i++){
         vector<bool> count(256);
         for(int j=i;j<n;j++){
             if(count[s[j]]==true){
                 break;
             }
             else {
                 res=max(res,j-i+1);
                 count[s[j]]=true;
             }
         }
    }
    return res;  
    }
};