class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int count=0,maxi=-1;
        for(int i=0;i<n;i++){
            if(nums[i]>maxi){
                maxi=nums[i];
            } else {
                maxi++;
                count+= maxi-nums[i];
                
            }
        }
        return count;
        
    }
};