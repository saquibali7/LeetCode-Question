class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> m;
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
        }
        vector<int> res;
        int temp1=0,idx=0;
        unordered_set<char> se;
        for(int i=0;i<s.length();i++){
            m[s[i]]--;
            if(se.find(s[i])!=se.end()){
                temp1--;
            } else {
                temp1+=m[s[i]];
                se.insert(s[i]);
            }
            if(temp1==0){
                res.push_back(i-idx+1);
                idx = i+1;
            }
        }
        return res;
    }
};