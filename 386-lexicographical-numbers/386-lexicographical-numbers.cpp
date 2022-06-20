class Solution {
public:
    void helper(vector<int> &res, int temp, int n){
        if(temp > n){
            return;
        }
        res.push_back(temp);
        for(int i=0;i<=9;i++){
            helper(res,10*temp+i,n);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for(int i=1;i<=9;i++){
            helper(res,i,n);
        }
        return res;
        
    }
};