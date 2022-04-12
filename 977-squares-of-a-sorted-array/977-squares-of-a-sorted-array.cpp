class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res;
        int n=nums.size();
        int j=0;
        while(j<n && nums[j]<0){
            j++;
        }
        int i=j-1;
        while(i>=0 && j<n){
            if(nums[i]*nums[i]<nums[j]*nums[j]){
                res.push_back(nums[i]*nums[i]);
                i--;
            } else {
                res.push_back(nums[j]*nums[j]);
                j++;
            }
        }
        while(i>=0){
            res.push_back(nums[i]*nums[i]);
            i--;
        }
        while(j<n){
            res.push_back(nums[j]*nums[j]);
            j++;
        }
        return res;
        
    }
};