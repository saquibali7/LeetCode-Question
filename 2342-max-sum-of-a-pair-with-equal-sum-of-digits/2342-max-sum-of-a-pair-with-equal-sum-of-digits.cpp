class Solution {
public:
    int numSum(int n){
        int res=0;
        while( n> 0){
            int rem=n%10;
            res+=rem;
            n/=10;
        }
        return res;
    }
    int maximumSum(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, priority_queue<int>> mp;
        for(int i=0;i<n;i++){
            mp[numSum(nums[i])].push(nums[i]);
        }
        int res=-1;
        for(auto i : mp){
            if(mp[i.first].size() > 1){
                int temp = mp[i.first].top();
                mp[i.first].pop();
                temp+=mp[i.first].top();
                res=max(res, temp);
            }
        }
        return res;
        
    }
};