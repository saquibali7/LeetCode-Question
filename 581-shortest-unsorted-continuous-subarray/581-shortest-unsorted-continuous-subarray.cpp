class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp=nums;
        sort(nums.begin(),nums.end());
        int i=0,j=n-1;
        while(i<n && nums[i]==temp[i]){
            i++;
        }
        while(j>-1 && nums[j]==temp[j]){
            j--;
        }
        if(i<j){
            return j-i+1;
        }
        return 0;
        
        
    }
};