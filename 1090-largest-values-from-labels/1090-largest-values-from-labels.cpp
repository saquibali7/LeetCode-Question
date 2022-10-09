class Solution {
public:
    static bool cmp(pair<int, int> a, pair<int, int> b){
        return a.first > b.first;
    }
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        vector<pair<int, int>> temp;
        int n=values.size();
        for(int i=0;i<n;i++){
            temp.push_back({values[i],labels[i]});
        }
        sort(temp.begin(),temp.end(),cmp);
        unordered_map<int, int> m;
        int count=0,res=0;
        for(int i=0;i<n;i++){
            if(count>=numWanted){
                break;
            }
            if(m[temp[i].second]>=useLimit){
                continue;
            }
            count++;
            res+=temp[i].first;
            m[temp[i].second]++;
        }
        return res;
    }
};