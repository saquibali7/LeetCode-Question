class Solution {
public:
    static bool mycmp(vector<int>&a, vector<int>&b){
        return a[1]<b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end(),mycmp);
        int count=1;
        int prev=pairs[0][1];
        for(int i=1;i<n;i++){
            if(prev<pairs[i][0]){
                count++;
                prev=pairs[i][1];
            }
        }
        return count;
        
    }
};