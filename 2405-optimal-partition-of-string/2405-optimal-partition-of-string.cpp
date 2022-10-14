class Solution {
public:
    int partitionString(string s) {
        unordered_map<char, int> m;
        int count=0;
        for(int i=0;i<s.length();i++){
            if(m.find(s[i])!=m.end()){
                m.clear();
                count++;
            }
            m[s[i]]++;
        }
        return count+1;
        
        
    }
};