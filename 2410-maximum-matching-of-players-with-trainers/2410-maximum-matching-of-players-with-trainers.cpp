class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int p=0,t=0;
        int count=0;
        int n=players.size(), m=trainers.size();
        while(p<n && t<m){
            while(t<m && players[p]>trainers[t]){
                t++;
            }
            if(t!=m){
                count++;
            }
            p++;
            t++;
        }
        return count;
    }
};