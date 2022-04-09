class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        stack<pair<int, int>> s;
        s.push({intervals[0][0],intervals[0][1]});
        for(int i=1;i<n;i++){
            if(intervals[i][0] > s.top().second){
                s.push({intervals[i][0],intervals[i][1]});
            }
            else if(intervals[i][1] > s.top().first){
                auto it = s.top();
                s.pop();
                it.second = max(it.second,intervals[i][1]);
                s.push(it);
                
            }
        }
        vector<vector<int>> res;
        while(s.size() > 0){
            vector<int> temp;
            temp.push_back(s.top().first);
            temp.push_back(s.top().second);
            s.pop();
            res.push_back(temp);
        }
        sort(res.begin(),res.end());
        return res;
        
    }
};