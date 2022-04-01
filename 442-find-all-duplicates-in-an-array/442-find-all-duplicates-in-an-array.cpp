class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        vector<int> res;
        for(auto it : m){
            if(it.second == 2){
                res.push_back(it.first);
            }
        }
        return res;
    }
};