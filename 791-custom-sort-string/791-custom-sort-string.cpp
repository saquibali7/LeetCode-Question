class Solution {
public:
    string customSortString(string order, string s) {
        int n=s.length();
        unordered_map<char, int> m;
        for(int i=0;i<n;i++){
            m[s[i]]++;
        }
        string res="";
        for(int i=0;i<order.length();i++){
            for(int j=0;j<m[order[i]];j++){
                res+=order[i];
            }
            m.erase(order[i]);
        }
        for(auto it : m){
            for(int i=0;i<it.second;i++){
                res+=it.first;
            }
        }
        return res;
    }
};