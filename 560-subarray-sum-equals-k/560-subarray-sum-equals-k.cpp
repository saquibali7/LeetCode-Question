class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0;
        int pre_sum=0;
        unordered_map<int,int> m;
        int n=nums.size();
        if(nums.size()==0){
            return 0;
        }
        for(int i=0;i<n;i++){
            pre_sum +=nums[i];
            if(pre_sum == k){
                count++;
            }
            if(m.find(pre_sum-k)!=m.end()){
               count+=m[pre_sum-k];
            }
            m[pre_sum]++;
        }
        return count;
    }
};