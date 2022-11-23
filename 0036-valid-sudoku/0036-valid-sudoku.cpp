class Solution {
public:
    bool helper(vector<vector<char>> &board, int a, int b,int c,int d){
        unordered_map<char,int> m;
        for(int i=a;i<b;i++){
            for(int j=c;j<d;j++){
                if(board[i][j]!='.'){
                    m[board[i][j]]++;
                }
            }
        }
        for(auto it : m){
            if(it.second>1){
                return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++){
            unordered_map<char,int> m;
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]!='.'){
                    m[board[i][j]]++;
                }
            }
            for(auto it : m){
                if(it.second>1){
                    return false;
                }
            }
        }
        for(int i=0;i<board.size();i++){
            unordered_map<char,int> m;
            for(int j=0;j<board[0].size();j++){
                if(board[j][i]!='.'){
                    m[board[j][i]]++;
                }
            }
            for(auto it : m){
                if(it.second>1){
                    return false;
                }
            }
        }
        int p=0,q;
        while(p<=6){
            q=0;
            while(q<=6){
                if(!helper(board,p,p+3,q,q+3)) return false;
                q=q+3;
            }
            p=p+3;
        }
        return true;
    }
};