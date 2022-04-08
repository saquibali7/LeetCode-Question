class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n=matches.size();
        unordered_map<int,int> w;
        unordered_map<int,int> l;
        for(int i=0;i<n;i++){
            w[matches[i][0]]++;
            l[matches[i][1]]++;
        }
        vector<vector<int>> res;
        vector<int> temp1;
        vector<int> temp2;
        for(auto it : w){
            if(l[it.first]==0){
                temp1.push_back(it.first);
            }
        }
        for(auto it : l){
            if(it.second==1){
                temp2.push_back(it.first);
            }
        }
        sort(temp1.begin(),temp1.end());
        sort(temp2.begin(),temp2.end());
        res.push_back(temp1);
        res.push_back(temp2);
        return res;
        
    }
};