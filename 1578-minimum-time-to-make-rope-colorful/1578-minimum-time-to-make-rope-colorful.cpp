class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int res=0;
        int pre_sum=0,mx=INT_MIN;
        bool flag=false;
        for(int i=1;i<colors.size();i++){
            if(colors[i]==colors[i-1]){
                if(!flag){
                    pre_sum+=neededTime[i-1];
                    mx = max(mx,neededTime[i-1]);
                }
                flag=true;
                pre_sum+=neededTime[i];
                mx = max(mx,neededTime[i]);
            } else {
                if(flag){
                    res+=(pre_sum-mx);
                }
                flag=false;
                pre_sum=0;
                mx=INT_MIN;
            }
        }
        if(flag){
            res+=(pre_sum-mx);
        }
        return res;
    }
};