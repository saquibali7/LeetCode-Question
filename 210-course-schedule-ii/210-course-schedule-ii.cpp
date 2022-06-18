class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        if(numCourses == 1){
            return {0};
        }
        vector<int> graph[2000];
        int indegree[2000]={0};
        for(int i=0;i<prerequisites.size();i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i] ==0){
                q.push(i);
            }
        }
        vector<int> res;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            res.push_back(curr);
            for(auto u : graph[curr]){
                indegree[u]--;
                if(indegree[u] == 0){
                    q.push(u);
                }
            }
        }
        if(res.size() == numCourses){
            return res;
        }
        return {};
    }
};