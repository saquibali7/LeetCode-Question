class Solution {
public:
    int fillCups(vector<int>& amount) {
        int n=amount.size();
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            if(amount[i]!=0){
                pq.push(amount[i]);
            }
        }
        int res=0;
        while(pq.size() > 1){
            int temp1=pq.top();
            pq.pop();
            int temp2=pq.top();
            pq.pop();
            temp1--;
            temp2--;
            if(temp1!=0){
                pq.push(temp1);
            }
            if(temp2!=0){
                pq.push(temp2);
            }
            res++;
        }
        if(!pq.empty()){
            res+=pq.top();
        }
        return res;
        
    }
};