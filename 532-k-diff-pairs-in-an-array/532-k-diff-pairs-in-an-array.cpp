class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> s;
        for(auto i : nums){
            s[i]++;
        }
        int count=0;
        if(k==0){
            for(auto i : s){
                if(i.second > 1){
                    count++;
                }
            }
            return count;
        }
        for(auto i : s){
            if(s.find(i.first-k)!=s.end()){
                count++;
            }
        }
        return count;
        
    }
};