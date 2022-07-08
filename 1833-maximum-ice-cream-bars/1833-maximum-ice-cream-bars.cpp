class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int cos=0,count=0;
        for(int i=0;i<costs.size();i++){
            if(cos+costs[i]<=coins){
                cos+=costs[i];
                count++;
            }
            if(cos>=coins || costs[i]>coins){
                break;
            }
        }
        return count;
        
    }
};