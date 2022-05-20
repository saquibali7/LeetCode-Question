class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        unordered_map<string,vector<string>> m;
        vector<vector<string>> res;
        for(int i=0;i<strs.size();i++){
            string curr=strs[i];
            sort(curr.begin(),curr.end());
            m[curr].push_back(strs[i]);
        }
        for(auto it : m){
            res.push_back(it.second);
        }
        return res;
        
    }
};