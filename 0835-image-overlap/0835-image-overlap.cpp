class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int, int>> v1,v2;
        int n=img1.size(),m=img1[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(img1[i][j]==1){
                    v1.push_back({i,j});
                }
                if(img2[i][j] == 1){
                    v2.push_back({i,j});
                }
            }
        }
        int res=0;
        map<pair<int, int>, int> m1;
        for(auto u1 : v1){
            for(auto u2 : v2){
                int d1 = u1.first-u2.first;
                int d2 = u1.second-u2.second;
                m1[{d1,d2}]++;
                res = max(res,m1[{d1,d2}]);
            }
        }
        return res;
    }
};