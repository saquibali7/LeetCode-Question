class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n=points.size();
        priority_queue<pair<double,int>> pq;
        for(int i=0;i<k;i++){
            double dis = abs(sqrt(points[i][0]*points[i][0] + 
                points[i][1]*points[i][1]));
            pq.push({dis,i});
        }
        for(int i=k;i<n;i++){
            double dis = abs(sqrt(points[i][0]*points[i][0] + 
                points[i][1]*points[i][1]));
            if(pq.top().first > dis ){
                pq.pop();
                pq.push({dis,i});
            }
        }
        vector<vector<int>> res;
        for(int i=0;i<k;i++){
            res.push_back(points[pq.top().second]);
            pq.pop();
        }
        return res;
        
    }
};