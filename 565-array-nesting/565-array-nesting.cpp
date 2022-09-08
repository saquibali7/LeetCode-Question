class Solution {
public:
    void DFS(int s,vector<int>& nums,vector<bool>& visited,int& count){
        if(visited[s]){
            return;
        }
        visited[s]=true;
        count++;
        DFS(nums[s],nums,visited,count);
    }
    int arrayNesting(vector<int>& nums) {
        int n=nums.size();
        vector<bool> visited(n,false);
        int res=INT_MIN;
        for(int i=0;i<n;i++){
            if(visited[i]){
                continue;
            }
            int count=0;
            DFS(nums[i],nums,visited,count);
            res=max(res,count);
        }
        
        return res;
    }
};