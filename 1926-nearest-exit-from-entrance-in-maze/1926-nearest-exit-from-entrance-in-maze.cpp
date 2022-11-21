class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n=maze.size(),m=maze[0].size();
        queue<pair<int,int>> q;
        q.push({entrance[0],entrance[1]});
        int res=INT_MAX, d=0;
        while(q.size() > 0){
            int size=q.size();
            for(int i=0;i<size;i++){
                pair<int,int> p=q.front();
                q.pop();
                if(p.first<0 || p.first>=n || p.second<0 || p.second>=m || maze[p.first][p.second]=='+'){
                      continue;
                }
                if((p.first==0 || p.first==n-1 || p.second==0 || p.second==m-1) && d!=0){
                      return d;
                }
                maze[p.first][p.second]='+';
                q.push({p.first+1,p.second});
                q.push({p.first-1,p.second});
                q.push({p.first,p.second+1});
                q.push({p.first,p.second-1});
            }
            d++;
        }
        if(res==INT_MAX) return -1;
        return res;
    }
};