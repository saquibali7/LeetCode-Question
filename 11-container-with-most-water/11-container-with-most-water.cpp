class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int res=0;
        int low=0,high=n-1;
        while(low<high){
            res = max(res, min(height[low],height[high])*(high-low));
            if(height[low] > height[high]){
                high = high-1;
            } else {
                low = low+1;
            }
        }
        return res;
    }
};