class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n=groupSizes.size();
        unordered_map<int, vector<int>> m2;
        for(int i=0;i<n;i++){
            m2[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> res;
        for(auto it : m2){
            vector<int> temp;
            int count=0;
            for(int i=0;i<it.second.size();i++){
                if(count==it.first){
                    res.push_back(temp);
                    temp.clear();
                    count=0;
                } 
                temp.push_back(it.second[i]);
                count++;
            }
            if(temp.size() > 0){
                res.push_back(temp);
            }
        }
        return res;
        
    }
};