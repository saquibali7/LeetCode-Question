class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m=s.size(),n=g.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(s[i]>=g[j]){
                    res++;
                    g[j]=INT_MAX;
                    break;
                }
            }
        }
        return res;
    }
};