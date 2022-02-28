class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        int product=1,n=nums.size(), count=0;
        bool flag=false;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                flag=true;
                count++;
            }
            if(nums[i]!=0){
                product *=nums[i];
            }
        }
        if(!flag){
            for(int i=0;i<n;i++){
                res.push_back(product/nums[i]);
            }
        }
        else if(count>1){
            for(int i=0;i<n;i++){
                res.push_back(0);
            }
        }
        else {
            for(int i=0;i<n;i++){
                if(nums[i]==0){
                    res.push_back(product);
                } else {
                    res.push_back(0);
                }
            }
        }
        return res;
    }
};