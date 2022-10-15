class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n=recipes.size();
        map<string, int> indegree;
        unordered_map<string, vector<string>> m;
        for(int i=0;i<n;i++){
            for(int j=0;j<ingredients[i].size();j++){
                m[ingredients[i][j]].push_back(recipes[i]);
                indegree[recipes[i]]++;
            }
        }
        vector<string> res;
        queue<string> q;
        for(auto i : supplies){
            q.push(i);
        }
        while(!q.empty()){
            string curr = q.front();
            q.pop();
            for(auto i : m[curr]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                    res.push_back(i);
                }
            }
        }
        return res;
        
    }
};