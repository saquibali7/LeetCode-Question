class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int mid=(n-1)/2;
        int count=0;
        for(int i=0;i<n;i++){
            count+=abs(nums[mid]-nums[i]);
        }
        return count;
        
    }
};