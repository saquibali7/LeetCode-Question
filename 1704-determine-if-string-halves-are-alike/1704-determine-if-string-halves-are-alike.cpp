class Solution {
public:
    bool halvesAreAlike(string s) {
        int n=s.length();
        int mid = n/2,count1=0,count2=0;;
        for(int i=0;i<mid;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i'|| s[i]=='o'|| s[i]=='u') count1++;
            else if(s[i]=='A' || s[i]=='E' || s[i]=='I'|| s[i]=='O'|| s[i]=='U') count1++;
            if(s[i+mid]=='a' || s[i+mid]=='e' || s[i+mid]=='i'|| s[i+mid]=='o'|| s[i+mid]=='u') count2++;
            else if(s[i+mid]=='A' || s[i+mid]=='E' || s[i+mid]=='I'|| s[i+mid]=='O'|| s[i+mid]=='U') count2++;
            
        }
        return count1==count2;
    }
};