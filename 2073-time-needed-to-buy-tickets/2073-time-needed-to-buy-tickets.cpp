class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n=tickets.size();
        queue<pair<int,int>> q;
        int count=0;
        for(int i=0;i<n;i++){
            q.push({tickets[i],i});
        }
        while(tickets[k]!=0){
            auto it = q.front();
            q.pop();
            it.first--;
            if(it.second==k){
                tickets[k]=it.first;
            }
            if(it.first!=0){
                q.push({it.first,it.second});
            };
            count++;
            
        }
        return count;
    }
};