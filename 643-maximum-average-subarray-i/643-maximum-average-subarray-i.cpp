class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        double pre_sum=0;
        for(int i=0;i<k;i++){
            pre_sum+=nums[i];
            m.insert({i,pre_sum});
        }
        double res= pre_sum/k;
        for(int i=k;i<nums.size();i++){
            pre_sum+=nums[i];
            if((pre_sum - m[i-k])/k > res){
                res = (pre_sum - m[i-k])/k;
            }
            m.insert({i,pre_sum});
        }
        return res;
        
    }
};