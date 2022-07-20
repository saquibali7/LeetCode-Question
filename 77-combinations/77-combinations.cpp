class Solution {
public:
    void helper(vector<vector<int>>& res, vector<int>& temp, int n, int k){
        if(temp.size()==k){
            res.push_back(temp);
            return;
        }
        if(n-1<0){
            return;
        }
        temp.push_back(n);
        helper(res,temp,n-1,k);
        temp.pop_back();
        helper(res,temp,n-1,k);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> temp;
        helper(res,temp,n,k);
        return res;
    }
    
};