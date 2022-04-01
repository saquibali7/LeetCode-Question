class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> res;
        for(int i=0;i<k;i++){
            pq.push({nums[i], i});
        }
        for(int i=k;i<n;i++){
            if(nums[i] > pq.top().first) {
                pq.pop();
                pq.push({nums[i],i});
            }
        }
        vector<int> temp;
        for(int i=0;i<k;i++){
            temp.push_back(pq.top().second);
            pq.pop();
            
        }
        sort(temp.begin(),temp.end());
        for(int i=0;i<k;i++){
            temp[i]= nums[temp[i]];
        }
        
        return temp;
        
    }
};