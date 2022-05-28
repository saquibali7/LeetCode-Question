class Solution {
public:
    void DFS(vector<vector<int>> &isConnected, int s, vector<bool> &visited){
        visited[s]=true;
        int n=isConnected.size();
        for(int i=0;i<n;i++){
            if(!visited[i] && isConnected[s][i]==1){
                DFS(isConnected,i,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool> visited(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                DFS(isConnected,i,visited);
                count++;
            }
        }
        return count;
        
    }
};