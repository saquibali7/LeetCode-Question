class Solution {
public:
    int wr;
    void DFS(vector<int> adj[], int s, vector<bool>& visited){
        visited[s]=true;
        for(auto u : adj[s]){
            if(!visited[u]){
                DFS(adj,u,visited);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        if(connections.size() < (n-1)){
            return -1;
        }
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        vector<bool> visited(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                DFS(adj,i,visited);
                count++;
            }
        }
        
        return count-1;
        
    }
};