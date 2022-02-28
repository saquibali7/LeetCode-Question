class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        unordered_map<int, int> m;
        int n= nums.size();
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        for(auto i: m){
            if(i.second > n/3){
                res.push_back(i.first);
            }
        }
        return res;
        
    }
};