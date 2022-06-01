class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> res;
        res.push_back(nums[0]);
        for(int i=1;i<n;i++){
            res.push_back(res[i-1]+nums[i]);
        }
        return res;
        
    }
};