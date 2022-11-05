class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        vector<vector<string>> res;
        unordered_map<string,int> m1;
        unordered_map<string,unordered_map<string,int>> m2;
        int n=creators.size();
        int temp=INT_MIN;
        for(int i=0;i<n;i++){
            m1[creators[i]]+=views[i];
            temp = max(temp,m1[creators[i]]);
            m2[creators[i]][ids[i]]+=views[i];
        }
        for(auto i : m1){
            if(i.second == temp){
                res.push_back({i.first});
            }
        }
        for(int i=0;i<res.size();i++){
            string temp1="";
            int v=-1;
            for(auto i : m2[res[i][0]]){
                if(i.second > v){
                    v=i.second;
                    temp1=i.first;
                } else if(i.second==v && i.first < temp1){
                    temp1=i.first;
                }
            }
            res[i].push_back(temp1);
        }
        return res;
        
    }
};