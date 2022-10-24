class Solution {
public:
    int n,m;
    vector<vector<int>> res;
    void dfs(vector<vector<int>> &matrix, int i, int j, int &p, int&q){
        if(i<0||i>=n ||j<0| j>=m || matrix[i][j]==0){
            return;
        }
        p=max(p,i);
        q=max(j,q);
        matrix[i][j]=0;
        dfs(matrix,i+1,j,p,q);
        dfs(matrix, i, j+1,p,q);
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        n=land.size(),m=land[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(land[i][j]==1){
                    int p=i,q=j;
                    dfs(land,i,j,p,q);
                    res.push_back({i,j,p,q});
                }
            }
        }
        return res;
    }
};