class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int res = INT_MAX, sum = 0;
        unordered_map<int,int> m;
        for(int i=n-1;i>=0;i--) {
            sum += nums[i];
            m[sum] = i + 1;
            if(sum == x){
                 res = min(res,n-i);
            }
        }
        sum = 0;
        for(int i = 0;i<n;i++){
            sum += nums[i];
            if(sum == x){
                res = min(res,i + 1);
            }
            if(m[x-sum] != 0 && m[x-sum] - 1> i){
                res = min(res,i+n - m[x-sum] + 2);
            }
        }
        return res == INT_MAX?-1:res;
        
    }
};