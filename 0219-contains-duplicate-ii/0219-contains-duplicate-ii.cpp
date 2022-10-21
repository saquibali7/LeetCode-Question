class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int, int> m;
        for(int i=0;i<n;i++){
            if(m.find(nums[i])!= m.end()){
                auto it = m.find(nums[i]);
                if(abs(it->second - i) <= k) {
                    return true;
                } 
                m[nums[i]]=i;
            } 
            else {
                m.insert({nums[i],i});
            }
        }
        return false;
        
        
    }
};