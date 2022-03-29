class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n=cost.size();
        sort(cost.begin(), cost.end(), greater<int>());
        int res=0;
        int count=1;
        for(int i=0;i<n;i++){
            if(count%3!=0){
                res+=cost[i];
            }
            count++;
        }
        return res;
        
    }
};