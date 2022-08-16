class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string,int> m;
        int n=grid.size();
        int count=0;
        for(int i=0;i<n;i++){
            string res="";
            for(int j=0;j<n;j++){
                res+=to_string(grid[i][j]);
                res+="#";
            }
            m[res]++;
        }
        for(int i=0;i<n;i++){
            string res="";
            for(int j=0;j<n;j++){
                res+=to_string(grid[j][i]);
                res+="#";
            }
            if(m.find(res)!=m.end()){
                count+=m[res];
            }
        }
        return count;
        
    }
};