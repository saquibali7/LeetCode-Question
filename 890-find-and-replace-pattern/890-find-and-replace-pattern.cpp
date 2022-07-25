class Solution {
public:
    bool isPattern(string s, string t){
        if(s.length()!=t.length()){
            return false;
        }
        map<char,char> m1,m2;
        for(int i=0;i<s.length();i++){
            m1[s[i]]=t[i];
            m2[t[i]]=s[i];
        }
        for(int i=0;i<s.length();i++){
            if(m1[s[i]]!=t[i] || m2[t[i]]!=s[i]){
                return false;
            }
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for(int i=0;i<words.size();i++){
            if(isPattern(pattern, words[i])){
                res.push_back(words[i]);
            }
        }
        return res;
    }
};