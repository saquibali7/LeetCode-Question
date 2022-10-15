class Solution {
public:
    static bool mycmp(pair<string,int>&p1,pair<string,int>&p2) {
        if(p1.second==p2.second)
        {
            return p1.first<p2.first;
        }
        return p1.second<p2.second;
    }
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n=friends.size();
        unordered_map<string,int> m;
        vector<int> temp;
        queue<int> q;
        q.push(id);
        q.push(-1);
        vector<bool> visited(n,false);
        visited[id]=true;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            if(curr==-1){
                q.push(-1);
                level--;
                if(level==0){
                    break;
                }
                temp.clear();
                continue;
            }
            for(auto i : friends[curr]){
                if(!visited[i]){
                    visited[i]=true;
                    temp.push_back(i);
                    q.push(i);
                }
            }
        }
        for(int i=0;i<temp.size();i++){
            for(int j=0;j<watchedVideos[temp[i]].size();j++){
                m[watchedVideos[temp[i]][j]]++;
            }
        }
        vector<string> res;
        vector<pair<string, int>> temp3;
        for(auto i : m){
            temp3.push_back({i.first,i.second});
        }
        sort(temp3.begin(),temp3.end(),mycmp);
        for (auto i : temp3){
            res.push_back(i.first);
        }
        return res;
    }
};