class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        int mod=pow(10,9)+7;
        int n=nums.size();
        priority_queue<int,vector<int>, greater<int>> pq;
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
        }
        for(int i=0;i<k;i++){
            int temp=pq.top();
            pq.pop();
            temp++;
            pq.push(temp);
        }
        long long int res=1;
        while(pq.size()>0){
            res*=pq.top();
            pq.pop();
            res = res%mod;
        }
        return res;
    }
};