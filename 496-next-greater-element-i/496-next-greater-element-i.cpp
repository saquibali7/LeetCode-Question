class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        vector<int> res;
        unordered_map<int, int>mp;
        for(int i=0;i<m;i++){
            mp.insert({nums2[i],i});
        }
        for(int i=0;i<n;i++){
            bool flag=false;
            int temp;
            for(int j=mp[nums1[i]];j<m;j++){
                if(nums2[j]>nums1[i]){
                    flag=true;
                    temp=nums2[j];
                    break;
                }
            }
            if(flag){
                res.push_back(temp);
            } else {
                res.push_back(-1);
            }
        }
        return res;
        
    }
};