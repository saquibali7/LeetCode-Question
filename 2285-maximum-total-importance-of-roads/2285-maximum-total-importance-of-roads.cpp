class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int, int> m;
        priority_queue<pair<int, int>> pq;
        for(int i=0;i<roads.size();i++){
            m[roads[i][0]]++;
            m[roads[i][1]]++;
        }
        unordered_map<int, int> m1;
        for(auto i : m){
            pq.push({i.second, i.first});
        }
        while(!pq.empty()){
            m1[pq.top().second]=n;
            n--;
            pq.pop();
        }
        long long int res=0;
        for(int i=0;i<roads.size();i++){
            res+=(m1[roads[i][0]] + m1[roads[i][1]]);
        }
        return res;
        
    }
};