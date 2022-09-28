class Solution {
public:
    unordered_set<int> s;
    int count=0;
    void dfs(int sr, vector<vector<int>> &adj, vector<bool> &visited){
        if(s.find(sr)!=s.end()){
            return;
        }
        if(visited[sr]){
            return;
        }
        visited[sr]=true;
        count++;
        for(auto i : adj[sr]){
            dfs(i,adj,visited);
        }
        
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        for(auto i : restricted){
            s.insert(i);
        }
        vector<vector<int>> adj(n);
        vector<bool> visited(n,false);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(0,adj,visited);
        return count;
        
    }
};