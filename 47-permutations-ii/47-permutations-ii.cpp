class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp = nums;
        do {
            next_permutation(temp.begin(), temp.end());
            res.push_back(temp); 
        } while(temp!=nums);
        return res;
        
    }
};
