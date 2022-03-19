class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();
        int p=0,q=m-1;
        while(p <=n-1 && q >=0){
            if(matrix[p][q]==target){
                return true;
            } 
            else if(target > matrix[p][q]){
                p++;
            }
            else {
                q--;
            }
        }
        return false;
        
    }
};