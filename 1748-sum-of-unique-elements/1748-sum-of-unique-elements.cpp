class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, int> m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        int sum =0;
        for(auto i:m){
            if(i.second == 1){
                sum +=i.first;
            }
        }
        return sum;
    }
};