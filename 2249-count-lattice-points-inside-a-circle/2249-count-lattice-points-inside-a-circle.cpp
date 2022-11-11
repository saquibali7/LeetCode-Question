class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        unordered_map<int,unordered_set<int>> m;
        for(int i=0;i<circles.size();i++){
            int x=circles[i][0],y=circles[i][1],r=circles[i][2];
            int x1 = circles[i][0]-circles[i][2],x2=circles[i][0]+circles[i][2];
            int y1 = circles[i][1]-circles[i][2],y2=circles[i][1]+circles[i][2];
            for(int i=x1;i<=x2;i++){
                for(int j=y1;j<=y2;j++){
                    if(((i-x)*(i-x)) + ((j-y)*(j-y))<=r*r){
                        m[i].insert(j);
                    }
                }
            }
        }
        int res=0;
        for(auto i : m){
            res+=i.second.size();
        }
        return res;
        
    }
};