class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
       map<int, int> m;
        for(auto i : nums){
            m[i]+=i;
        }
        int curr=0,pre=0;
        for(auto i : m){
            if(m.find(i.first-1)==m.end()){
                pre=curr;
                curr+=i.second;
            } else {
                int temp = max (curr, pre+i.second);
                pre=curr;
                curr=temp;
            }
        }
        return curr;
    }
};