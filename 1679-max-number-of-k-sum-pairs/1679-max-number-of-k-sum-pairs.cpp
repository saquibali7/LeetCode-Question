class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int low=0,high=n-1,count=0;
        while(low<high){
            if(nums[low]+nums[high]==k){
                count++;
                low++;
                high--;
            }
            else if(nums[low]+nums[high]>k){
                high--;
            } else {
                low++;
            }
        }
        return count;
        
    }
};