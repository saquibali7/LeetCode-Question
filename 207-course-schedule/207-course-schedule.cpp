class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        if(numCourses == 1 || prerequisites.size()==0) {
            return true;
        }
        vector<vector<int>> graph(n);
        vector<int> indegree(n,0);
        for(int i=0;i<prerequisites.size();i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i] ==0){
                q.push(i);
            }
        }
        int count = 0;
        while(!q.empty()){
            count++;
            int curr = q.front();
            q.pop();
            for(auto u : graph[curr]){
                indegree[u]--;
                if(indegree[u] == 0){
                    q.push(u);
                }
            }
        }
        return (count == numCourses);

    }
        
};