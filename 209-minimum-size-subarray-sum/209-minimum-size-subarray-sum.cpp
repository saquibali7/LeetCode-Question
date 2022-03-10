class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>=target){
                return 1;
            }
        }
        int res = n+1;
        bool flag=false;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum += nums[j];
                if(sum>=target){
                    flag=true;
                    res=min(res,j-i+1);
                    break;
                }
            }
        }
        if(!flag){
            return 0;
        }
        return res;
    }
};