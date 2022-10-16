class Solution {
public:
    int edgeScore(vector<int>& edges) {
        unordered_map<int, int> m;
        for(int i=0;i<edges.size();i++){
            m[i]=edges[i];
        }
        long long int maxValue=INT_MIN;
        unordered_map<int, long long int> m1;
        for(auto i : m){
            m1[i.second]+=i.first;
        }
        for(auto i : m1){
            maxValue=max(maxValue,i.second);
        }
        int res=INT_MAX;
        for(auto i : m1){
            if(i.second == maxValue && i.first < res){
                res=i.first;
            }
        }
        return res;
    }
};