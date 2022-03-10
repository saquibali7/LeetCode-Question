class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int pre_sum=0,post_sum=0;
            for(int j=0;j<=i-1;j++){
                pre_sum+=nums[j];
            }
            for(int k=i+1;k<n;k++){
                post_sum+=nums[k];
            }
            if(pre_sum == post_sum){
                return i;
            }
        }
        return -1;
    }
};