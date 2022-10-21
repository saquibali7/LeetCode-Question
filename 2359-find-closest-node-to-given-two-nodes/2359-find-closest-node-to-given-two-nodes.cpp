class Solution {
public:
    void dfs(unordered_map<int, int> &m, int count, int s,vector<bool> &visited,
            unordered_map<int, int> &n){
        visited[s]=true;
        n.insert({s,count});
        if(m.find(s)==m.end()){
            return;
        }
        if(!visited[m[s]]){
            dfs(m,count+1,m[s],visited,n);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        unordered_map<int, int> m;
        int n=edges.size();
        for(int i=0;i<n;i++){
            if(edges[i]==-1){
                continue;
            }
            m[i]=edges[i];
        }
        vector<bool> visited1(n,false);
        vector<bool> visited2(n,false);
        unordered_map<int, int> n1;
        unordered_map<int, int> n2;
        dfs(m,0,node1,visited1,n1);
        dfs(m,0,node2,visited2,n2);
        int res=INT_MAX,curr=INT_MAX,temp;
        for(auto i : n1){
            if(n2.find(i.first)!=n2.end()){
                temp=max(i.second,n2[i.first]);
                if(temp<curr){
                    curr=temp;
                    res=i.first;
                } else if(temp==curr && i.first < res){
                    res=i.first;
                }
            }
        }
        if(res!=INT_MAX){
            return res;
        }
        return -1;
    }
};