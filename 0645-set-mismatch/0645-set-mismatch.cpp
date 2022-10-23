class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res;
        int n=nums.size();
        int sum=(n*(n+1))/2,curr_sum=0,miss,d;
        unordered_set<int> s;
        for(int i=0;i<n;i++){
            if(s.find(nums[i])!=s.end()){
                d=nums[i];
                continue;
            }
            curr_sum+=nums[i];
            s.insert(nums[i]);
        }
        res.push_back(d);
        res.push_back(sum-curr_sum);
        return res;
    }
};