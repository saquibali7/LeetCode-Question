class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int count=0;
    KthLargest(int k, vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(k>0){
                pq.push(nums[i]);
                k--;
            } else if(nums[i]>pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        count=k;
    }
    
    int add(int val) {
        if(count>0){
            pq.push(val);
            count--;
            return pq.top();
        } else if(val > pq.top()){
            pq.pop();
            pq.push(val);
            return pq.top();
        } else {
            return pq.top();
        }
        return -1;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */