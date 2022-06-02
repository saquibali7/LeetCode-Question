class Solution {
public:
    void helper(vector<vector<int>> rooms, int s, vector<bool> &visited){
        visited[s]=true;
        for(int i : rooms[s]){
            if(!visited[i]){
                helper(rooms, i, visited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> visited(n,false);
        helper(rooms, 0 ,visited);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                return false;
            }
        }
        return true;
        
    }
};