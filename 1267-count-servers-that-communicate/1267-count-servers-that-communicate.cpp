class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        unordered_map<int, int> m1;
        unordered_map<int, int> m2;
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    count++;
                    m1[i]++;
                    m2[j]++;
                }
            }
        }
        int count1=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1 && m1[i]==1 && m2[j]==1){
                    count1++;
                    m1[i]++;
                    m2[j]++;
                }
            }
        }
        return count-count1;
        
    }
};