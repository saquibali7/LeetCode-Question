class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        vector<int> temp;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            if(grid[i][0]==0){
                for(int j=0;j<m;j++){
                    grid[i][j]=1-grid[i][j];
                }
            }
        }
        for(int i=0;i<m;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(grid[j][i]==0){
                    count++;
                }
            }
            if(count>n/2){
              for(int j=0;j<n;j++){
                grid[j][i]=1-grid[j][i];
              }
            }
        }
        int res=0;
        for(int i=0;i<n;i++){
            int temp=0,pow=1;
            for(int j=m-1;j>=0;j--){
                temp += grid[i][j]*pow;
                pow*=2;
            }
            res+=temp;
        }
        return res;
        
    }
};