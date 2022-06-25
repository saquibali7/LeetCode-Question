class Solution {
public:
    static bool mycmp(vector<int> a, vector<int> b){
        return a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int n=points.size();
        int count=0;
        int mini=points[0][1];
        for(int i=1;i<n;i++){
            if(points[i][0] <= mini){
                count++;
                mini=min(points[i][1],mini);
            } else {
                
                mini=points[i][1];
            }
        }
        return n-count;
        
    }
};