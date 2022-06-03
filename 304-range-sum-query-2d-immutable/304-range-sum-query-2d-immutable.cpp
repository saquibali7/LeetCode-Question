class NumMatrix {
public:
    vector<vector<int>> temp;
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        temp=vector<vector<int>>(n+1, vector<int>(m+1));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                temp[i][j]=temp[i-1][j]+temp[i][j-1]-temp[i-1][j-1]+matrix[i-1][j-1];
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res=0;
        row1++,col1++,row2++,col2++;
        res=temp[row2][col2]-temp[row2][col1-1]-temp[row1-1][col2]+temp[row1-1][col1-1];
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */