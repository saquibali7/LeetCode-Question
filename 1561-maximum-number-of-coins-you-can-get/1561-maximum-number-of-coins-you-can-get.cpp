class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n=piles.size();
        int count = n/3;
        sort(piles.begin(),piles.end());
        priority_queue<int> pq;
        for(int i=count;i<n;i++){
            pq.push(piles[i]);
        }
        int res=0;
        while(!pq.empty()){
            pq.pop();
            res+=pq.top();
            pq.pop();
        }
        return res;
    }
};