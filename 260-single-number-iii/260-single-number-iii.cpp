class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, int> m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
            if(m[nums[i]]==2){
                m.erase(nums[i]);
            }
        }
        vector<int> res;
        for(auto it : m){
            if(it.second==1){
                res.push_back(it.first);
            }
        }
        return res;
    }
};