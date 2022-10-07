class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++){
            for(auto u : adj[i]){
                indegree[u]++;
            }
        }
        vector<vector<int>> res;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
                
            }
        }
        unordered_map<int,set<int>> m;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto u : adj[curr]){
                indegree[u]--;
                if(indegree[u]==0){
                    q.push(u);
                }
                for(auto i : m[curr]){
                    m[u].insert(i);
                }
                m[u].insert(curr);
            }
        }
        for(int i=0;i<n;i++){
            vector<int> temp;
            for(auto u : m[i]){
                temp.push_back(u);
            }
            res.push_back(temp);
        }
        return res;
    }
};