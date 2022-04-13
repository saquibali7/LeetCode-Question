class Solution {
public:
    int halveArray(vector<int>& nums) {
        int n=nums.size();
        priority_queue<double> pq;
        double sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            pq.push(nums[i]);
        }
        double res=0,temp=0;
        int count=0;
        while(res<sum/2){
            temp = pq.top()/2;
            pq.pop();
            pq.push(temp);
            count++;
            res+=temp;
            
        }
        return count;
        
    }
};