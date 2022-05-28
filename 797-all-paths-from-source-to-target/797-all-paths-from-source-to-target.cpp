class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<vector<int>>& graph,int s, vector<int> temp){
        temp.push_back(s);
        if(s==graph.size()-1){
            res.push_back(temp);
        }
        for(auto it : graph[s]){
            helper(graph, it, temp);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> temp;
        helper(graph,0, temp);
        return res;
        
        
    }
};