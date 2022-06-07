class Solution {
public:
    bool helper(vector<int>& arr, int start, vector<bool>& visited){
        if(start < 0 || start>=arr.size()){
            return false;
        }
        if(visited[start]){
            return false;
        }
        visited[start]=true;
        if(arr[start]==0){
            return true;
        }
        if(helper(arr, start+arr[start],visited)){
            return true;
        }
        if(helper(arr, start-arr[start], visited)){
            return true;
        }
        return false; 
    }
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<bool> visited(n, false);
        return helper(arr,start,visited);
           
        
    }
};