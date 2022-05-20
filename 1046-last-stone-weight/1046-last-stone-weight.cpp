class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size()==1){
            return stones[0];
        }
        priority_queue<int> pq;
        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }
        while(pq.size()>1){
            int temp1=pq.top();
            pq.pop();
            int temp2=pq.top();
            pq.pop();
            if(temp1==temp2){
                continue;
            } else {
                pq.push(abs(temp1-temp2));
            }
        }
        if(!pq.empty()){
            return pq.top();
        }
        return 0;
    }
};