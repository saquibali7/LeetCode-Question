class Solution {
public:
    void swap(int *a, int *b){
        int temp=*b;
        *b=*a;
        *a=temp;
        
    }
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();
        vector<vector<int>> res;
        for(int i=0;i<m;i++){
            vector<int> temp;
            for(int j=0;j<n;j++){
                temp.push_back(matrix[j][i]);
            }
            res.push_back(temp);
        }
        return res;
    }
};