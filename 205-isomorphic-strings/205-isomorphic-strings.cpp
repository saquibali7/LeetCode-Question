class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> m1,m2;
        for(int i=0;i<s.length();i++){
            m1[s[i]]=t[i];
            m2[t[i]]=s[i];
        }
        for(int i=0;i<s.length();i++){
            if(m1[s[i]]!=t[i] || m2[t[i]]!= s[i]) return false;
        }
        return true;
        
    }
};