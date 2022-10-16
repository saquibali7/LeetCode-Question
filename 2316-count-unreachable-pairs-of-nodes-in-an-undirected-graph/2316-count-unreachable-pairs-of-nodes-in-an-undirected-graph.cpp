class Solution {
public:
    void dfs(int s, vector<vector<int>> &adj,vector<bool> &visited, int &count){
        visited[s]=true;
        count++;
        for(auto u : adj[s]){
            if(!visited[u]){
                dfs(u,adj,visited,count);
            }
        }
        
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> temp;
        vector<bool> visited(n,false);
        long long int res=0,temp1;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                int count=0;
                dfs(i,adj,visited,count);
                temp.push_back(count);
                temp1=(n-count);
                temp1=count*temp1;
                res+=temp1;
            }
        }
        
       return res/2;
            
            
    }
};