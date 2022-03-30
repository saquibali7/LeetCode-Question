class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int> &nums, vector<int> temp, int i){
        if(i==nums.size()){
            res.push_back(temp);
            return;
        }
        helper(nums,temp,i+1);
        temp.push_back(nums[i]);
        helper(nums,temp,i+1);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        int i=0;
        helper(nums,temp,i);
        return res;
    }
    
};