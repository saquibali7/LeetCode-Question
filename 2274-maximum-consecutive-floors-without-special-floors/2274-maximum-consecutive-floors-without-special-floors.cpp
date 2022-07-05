class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(),special.end());
        int res=0,n=special.size();
        for(int i=1;i<n;i++){
            res=max(res,special[i]-special[i-1]-1);
        }
        res = max(res,max(special[0]-bottom,top-special[n-1]));
        return res;
        
    }
};