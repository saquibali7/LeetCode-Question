class Solution {
public:
    bool res=false;
    void DFS(vector<int> edges[], int s, vector<bool> &visited, int d){
        visited[s]=true;
        if(s==d){
            res=true;
        }
        for(auto i : edges[s]){
            if(!visited[i]){
                DFS(edges,i, visited,d);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> visited(n, false);
        vector<int> edge[n];
        for(int i=0;i<edges.size();i++){
            edge[edges[i][0]].push_back(edges[i][1]);
            edge[edges[i][1]].push_back(edges[i][0]);
        }
        
        DFS(edge,source,visited,destination);
        return res;
        
    }
};