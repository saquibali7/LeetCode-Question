class Solution {
public:
    static bool mycmp(vector<int> a, vector<int> b) {
        return a[1]<b[1];
    }
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), mycmp);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int p=0, n=trips.size();
        for(int i=0;i<n;i++){
            while( !pq.empty() && pq.top().first <= trips[i][1]){
                p-=pq.top().second;
                pq.pop();
            }
            pq.push({trips[i][2], trips[i][0]});
            p+=trips[i][0];
            if(p> capacity){
                return false;
            }
        }
        return true;
    }
};