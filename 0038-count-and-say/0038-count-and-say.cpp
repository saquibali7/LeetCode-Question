class Solution {
public:
    string countAndSay(int n) {
        string s="1";
        if(n==1){
            return s;
        }
        
        while(n>1){
            unordered_map<int, int> m;
            string temp="";
            for(int i=0;i<s.length();i++){
                if(s.length()==1 || (i!=s.size()-1 && s[i]!=s[i+1]) 
                   || i==s.size()-1){
                    m[s[i]-'0']++;
                    temp+=to_string(m[s[i]-'0']);
                    m.erase(s[i]-'0');
                    temp+=s[i];
                } else if((s[i]==s[i+1]) ){
                    m[s[i]-'0']++;
                }
            }
            s=temp;
            n--;
        }
        return s;
    }
};