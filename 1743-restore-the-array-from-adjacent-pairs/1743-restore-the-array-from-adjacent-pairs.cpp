class Solution {
public:
    vector<int> res;
    void dfs(unordered_map<int, vector<int>>& m,int f, int p){
        res.push_back(f);
        for(auto i: m[f]){
            if(i!=p){
                dfs(m,i,f);
            }
        }
    }
    
    
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>> m1;
        unordered_map<int, int> m2;
        int f;
        int n=adjacentPairs.size();
        for(int i=0;i<n;i++){
            m1[adjacentPairs[i][0]].push_back(adjacentPairs[i][1]);
            m1[adjacentPairs[i][1]].push_back(adjacentPairs[i][0]);
            m2[adjacentPairs[i][0]]++;
            m2[adjacentPairs[i][1]]++;
        }
        for(auto i : m2){
            if(i.second == 1){
                f=i.first;
                break;
            }
        }
        dfs(m1, f, INT_MAX);
        return res;
    }
};