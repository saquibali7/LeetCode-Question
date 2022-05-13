class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int,int> m;
        for(auto it : nums){
            for(int i=0;i<it.size();i++){
                m[it[i]]++;
            }
        }
        vector<int> res;
        for(auto it : m){
            if(it.second == nums.size()){
                res.push_back(it.first);
            }
        }
        sort(res.begin(),res.end());
        return res;
        
    }
};