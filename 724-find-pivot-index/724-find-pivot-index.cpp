class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int pre_sum[n],post_sum[n];
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            pre_sum[i]=sum;
        }
        int post=sum;
        for(int i=0;i<n;i++){
            post_sum[i]=post;
            post -= nums[i];
            
        }
        for(int i=0;i<n;i++){
            if(post_sum[i]==pre_sum[i]){
                return i;
            }
        }
        return -1;
    }
};