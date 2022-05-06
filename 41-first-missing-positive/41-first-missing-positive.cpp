class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        int count=1;
        while(true){
            if(s.find(count)==s.end()){
                return count;
            }
            count++;
        }
        return -1;
    }
};