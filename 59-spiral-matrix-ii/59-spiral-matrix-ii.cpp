class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int> (n));
        int p=0,x=0,y=0;
        int count=0;
        int m=n;
        while(x<n && y<m){
            for(p=y;p<m;p++){
                res[x][p]=++count;
            }
            x++;
            for(p=x;p<n;p++){
                res[p][m-1]=++count;
            }
            m--;
            if(x<n){
                for(p=m-1;p>=y;p--){
                    res[n-1][p]=++count;
                }
                n--;
            }
            if(y<m){
                for(p=n-1;p>=x;p--){
                    res[p][y]=++count;
                }
                y++;
            }
        }
        return res;
    }
};