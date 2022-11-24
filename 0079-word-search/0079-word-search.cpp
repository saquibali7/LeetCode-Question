class Solution {
public:
    string res;
    int n,m;
    unordered_set<string> se;
    bool helper(vector<vector<char>> &board, int i, int j, vector<vector<bool>> &visited,int idx){
        if(idx == res.length()) return true;
        if(i<0 || i>=n || j<0 || j>=m || visited[i][j] || res[idx]!=board[i][j]){
            return false;
        }
        
        visited[i][j]=true;
        bool a = helper(board,i+1,j,visited,idx+1);
        bool b = helper(board,i,j+1,visited,idx+1);  
        bool c = helper(board,i-1,j,visited,idx+1);
        bool d = helper(board,i,j-1,visited,idx+1);
        visited[i][j]=false;
        return a|| b|| c|| d;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n=board.size(),m=board[0].size();
        res=word;
        vector<vector<bool>> visited(n,vector<bool> (m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int idx=0;
                if(helper(board,i,j,visited,idx)) return true;
            }
        }
        return false;
    }
};