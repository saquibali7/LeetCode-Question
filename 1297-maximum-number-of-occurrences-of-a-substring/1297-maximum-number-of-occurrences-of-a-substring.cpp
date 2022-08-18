class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int> m;
        int n=s.length();
        for(int i=0;i<n;i++){
            unordered_set<char> se;
            string temp="";
            for(int j=i;j<n;j++){
                temp+=s[j];
                se.insert(s[j]);
                if(se.size() <= maxLetters && 
                   temp.size()>=minSize && temp.size()<=maxSize){
                    m[temp]++;
                }
                if(se.size() > maxLetters || temp.size() > maxSize){
                    break;
                }
            }
        }
        int res=0;
        for(auto i : m){
            res = max(res, i.second);
        }
        return res;
    }
};