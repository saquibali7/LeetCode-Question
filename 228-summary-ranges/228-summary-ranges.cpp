class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n=nums.size();
        if(n==0){
            return res;
        }
        
        int i=0;
        while(i<=n-1){
            if( i!=n-1 && nums[i]+1==nums[i+1]){
                string temp=to_string(nums[i]) + "-" + ">";
                while(i!=n-1 && nums[i]+1==nums[i+1]){
                    i++;
                }
                temp+= to_string(nums[i]);
                res.push_back(temp);
                i++;
            } else if(i == n-1){
                res.push_back(to_string(nums[i]));
                i++;
            } else if(nums[i] != nums[i+1]+1 && i!=n-1) {
                res.push_back(to_string(nums[i]));
                i++;
            }
            else{
                continue;
            }
        }
        return res;
    }
};