class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        unordered_map<int, string> m1;
        m1[1]="Gold Medal";
        m1[2]="Silver Medal";
        m1[3]="Bronze Medal";
        vector<int> temp=score;
        sort(temp.begin(),temp.end());
        unordered_map<int, int> m2;
        for(int i=0;i<n;i++){
            m2[temp[i]]=n-i;
        }
        vector<string> res;
        for(int i=0;i<n;i++){
            int rank=m2[score[i]];
            if(m1.find(rank)!=m1.end()){
                res.push_back(m1[rank]);
            } else {
                res.push_back(to_string(rank));
            }
        }
        return res;
    }
};