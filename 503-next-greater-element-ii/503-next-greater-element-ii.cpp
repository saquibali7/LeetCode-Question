class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int> s;
        vector<int> res;
        int temp=nums[n-1];
        bool flag=false;
        for(int i=n-1;i>=0;i--){
            s.push(nums[i]);
        }
        for(int i=n-1;i>=0;i--){
            while(s.empty()==false && s.top()<=nums[i]){
                s.pop();
            }
            int temp2 = (s.empty())?-1:s.top();
            res.push_back(temp2);
            s.push(nums[i]);
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
};