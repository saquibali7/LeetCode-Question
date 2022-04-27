class Solution {
public:
    static bool mycmp(vector<int> a, vector<int> b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(), mycmp);
        stack<vector<int>> s;
        s.push(intervals[0]);
        for(int i=1;i<n;i++){
            if(intervals[i][0] >= s.top()[0] && intervals[i][1]<=s.top()[1]){
                continue;
            } else {
                s.push(intervals[i]);
            }
        }
        return s.size();
    }
};