class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n= wall.size(),v;
        unordered_map<int, int> m;
        for(int i=0;i<n;i++){
            int temp=0;
            for(int j=0;j<wall[i].size();j++){
                temp+=wall[i][j];
                m[temp]++;
            }
            v=temp;
        }
        int mx=0;
        for(auto i : m){
            if(i.first==v){
                continue;
            }
            mx = max(i.second, mx);
        }
        return (n-mx);
    }
};