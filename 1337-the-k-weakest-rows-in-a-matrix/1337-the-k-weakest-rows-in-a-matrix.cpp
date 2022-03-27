class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        map<int, int> m;
        vector<int> temp;
        int n=mat.size(),p=mat[0].size();
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<p;j++){
                if(mat[i][j]==1){
                    count++;
                }
            }
            m.insert({i,count});
            temp.push_back(count);
        }
        sort(temp.begin(), temp.end());
        vector<int> res;
        for(int i=0;i<k;i++){
            for(auto it : m){
                if(it.second==temp[i]){
                    res.push_back(it.first);
                    m.erase(it.first);
                    break;
                }
            }
        }
        return res;
        
    }
};