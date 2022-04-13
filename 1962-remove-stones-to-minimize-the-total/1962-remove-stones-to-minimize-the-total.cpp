class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n=piles.size();
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            pq.push(piles[i]);
        }
        for(int i=0;i<k;i++){
            int temp=pq.top();
            temp=temp-floor(temp/2);
            pq.pop();
            pq.push(temp);
        }
        int res=0;
        while(pq.size()>0){
            res+=pq.top();
            pq.pop();
        }
        return res;
    }
};