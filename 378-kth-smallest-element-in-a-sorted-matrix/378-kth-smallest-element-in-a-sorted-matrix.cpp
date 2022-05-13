class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            for(int j=0;j<matrix[i].size();j++){
                if(k>0){
                    pq.push(matrix[i][j]);
                    k--;
                } else if(matrix[i][j]<pq.top()){
                    pq.pop();
                    pq.push(matrix[i][j]);
                } else {
                    break;
                }
            }
        }
        return pq.top();
    }
};