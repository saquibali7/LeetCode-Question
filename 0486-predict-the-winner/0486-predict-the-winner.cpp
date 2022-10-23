class Solution {
public:
    int helper(vector<int> &nums, int l, int r){
        if(l>r){
            return 0;
        }
        if(l==r){
            return nums[l];
        }
        int s1 = nums[l]+min(helper(nums,l+1,r-1),helper(nums,l+2,r));
        int s2 = nums[r]+min(helper(nums,l+1,r-1),helper(nums,l,r-2));
        return max(s1,s2);    
    }
    bool PredictTheWinner(vector<int>& nums) {
        int sum=0;
        for(auto i : nums){
            sum+=i;
        }
        int p2 = sum-helper(nums,0,nums.size()-1);
        if(helper(nums,0,nums.size()-1) >= p2){
            return true;
        }
        return false;
    }
};