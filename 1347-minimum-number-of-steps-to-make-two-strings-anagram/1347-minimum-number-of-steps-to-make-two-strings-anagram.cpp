class Solution {
public:
    int minSteps(string s, string t) {
        int count[26]={0};
        int n=s.length();
        for(int i=0;i<n;i++){
            count[s[i]-'a']++;
        }
        for(int i=0;i<n;i++){
            count[t[i]-'a']--;
        }
        int res=0;
        for(int i=0;i<26;i++){
            if(count[i]<0){
                res+=count[i];
            }
        }
        res = abs(res);
        return res;
        
    }
};