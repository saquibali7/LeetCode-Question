class Solution {
public:
    int n,m;
    void dfs(vector<vector<char>>& board, int i, int j){
        if(i<0 || i>=n || j<0 || j>=m || board[i][j]=='.'){
            return;
        }
        board[i][j]='.';
        dfs(board,i+1,j);
        dfs(board,i,j+1);
        
    }
    int countBattleships(vector<vector<char>>& board) {
        n=board.size(),m=board[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]!='.'){
                    dfs(board,i,j);
                    count++;
                }
            }
        }
        return count;
        
        
    }
};