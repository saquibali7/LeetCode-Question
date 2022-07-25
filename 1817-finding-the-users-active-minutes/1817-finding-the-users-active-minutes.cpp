class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> ms;
        for(int i=0;i<logs.size();i++){
            ms[logs[i][0]].insert(logs[i][1]);
        }
        unordered_map<int, int> m;
        for(auto i : ms){
            m[i.second.size()]++;
        }
        vector<int> res;
        for(int i=1;i<=k;i++){
            res.push_back(m[i]);
        }
        return res;
        
    }
};