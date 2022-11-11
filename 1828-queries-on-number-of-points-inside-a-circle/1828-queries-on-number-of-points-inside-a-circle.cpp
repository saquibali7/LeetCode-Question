class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> res;
        for(int i=0;i<queries.size();i++){
            int x=queries[i][0],y=queries[i][1],r=queries[i][2];
            int count=0;
            for(int j=0;j<points.size();j++){
                if(((points[j][0]-x)*(points[j][0]-x)) + ((points[j][1]-y)*(points[j][1]-y))<=r*r){
                    count++;
                }
            }
            res.push_back(count);
        }
        return res;
        
    }
};