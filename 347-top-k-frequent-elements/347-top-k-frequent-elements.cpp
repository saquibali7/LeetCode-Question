class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1 && k==1){
            return nums;
        }
        vector<int> res;
        unordered_map<int, int> m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        int count=0,max=0,temp=0;
        for(int j=0;j<k;j++){
            for(auto i: m){
                if(i.second > max){
                    max = i.second;
                    temp = i.first;
                }
            }
            res.push_back(temp);
            max=0;
            m.erase(temp);
         }
        return res;
        
    }
};