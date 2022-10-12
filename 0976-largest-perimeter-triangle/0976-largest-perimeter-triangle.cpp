class Solution {
public:
    bool isTri(int a, int b, int c){
        if((a+b > c) && (b+c)>a && (c+a) >b){
            return true;
        }
        return false;
    }
    int largestPerimeter(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=n-1;i>=2;i--){
            if(isTri(nums[i],nums[i-1],nums[i-2])){
                return nums[i]+nums[i-1]+nums[i-2];
            }
        }
        return 0;
        
    }
};