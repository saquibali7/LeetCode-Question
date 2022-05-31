class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        int temp=n;
        for(int i=0;i<n;i++){
            for(int j=0;j<temp-1;j++){
                int prev=nums[j+1];
                nums[j]=(nums[j]+prev)%10;
            }
            temp--;
        }
        return nums[0];
        
    }
};