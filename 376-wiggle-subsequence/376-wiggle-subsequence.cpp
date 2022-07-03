class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        int i=0,count=1;
        while(i<n-1){
            if(nums[i+1]>nums[i]){
                count++;
                while(i<n-1 && nums[i+1]>=nums[i]){
                    i++;
                }
            }
            else if(nums[i]>nums[i+1]){
                count++;
                while(i<n-1 && nums[i]>=nums[i+1]){
                    i++;
                }
            } else {
                i++;
            }
        }
        return count;
    }
};