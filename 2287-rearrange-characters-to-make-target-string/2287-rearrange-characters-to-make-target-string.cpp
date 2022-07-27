class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char, int> m;
        unordered_map<char, int> m1;
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
        }
        int res=INT_MAX;
        for(int i=0;i<target.size();i++){
            m1[target[i]]++;
        }
        for(auto i : m1){
            if(floor(m[i.first]/i.second) < res){
                res=floor(m[i.first]/i.second);
            }
        }
        return res;
        
    }
};