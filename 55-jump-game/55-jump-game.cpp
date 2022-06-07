class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<bool> visited(n,false);
        visited[0]=true;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                continue;
            }
            for(int j=1;j<=nums[i];j++){
                visited[i+j]=true;
                if(visited[n-1]){
                    return true;
                }
            }
        }
        return visited[n-1];
    }
};