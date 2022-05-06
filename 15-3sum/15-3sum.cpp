class Solution {
public:
    vector<vector<int>> res;
    void sum2(vector<int> &nums,int low,int high, int num){
        while(low<high){
            if(nums[low]+nums[high] == -num){
                res.push_back({num,nums[low],nums[high]});
                while(low<high && nums[high]==nums[high-1]){
                    high--;
                }
                while(low<high && nums[low]==nums[low+1]){
                    low++;
                }
                low++;
                high--;
            }
            else if(nums[low]+nums[high] > -num){
                high--;
            }else {
                low++;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0;i<n-2;i++){
            if (i >0 && nums[i] == nums[i-1]) {
                continue;
            }
            sum2(nums,i+1,n-1,nums[i]);
        }
        return res; 
    }
};