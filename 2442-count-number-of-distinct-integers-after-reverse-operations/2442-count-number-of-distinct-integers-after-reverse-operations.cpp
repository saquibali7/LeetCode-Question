class Solution {
public:
    int rev(int n){
        int res=0;
        while(n>0){
            int rem = n%10;
            res = res*10+rem;
            n/=10;
        }
        return res;
    }
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> s;
        for(auto i : nums){
            s.insert(i);
        }
        for(int i=0;i<nums.size();i++){
            s.insert(rev(nums[i]));
        }
        return s.size();
        
    }
};