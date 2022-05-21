class Solution {
public:
    int setBits(int a){
        int res=0;
        while(a>0){
            a= (a & (a-1));
            res++;
        }
        return res;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int, int>> temp;
        for(int i=0;i<arr.size();i++){
            temp.push_back({setBits(arr[i]),arr[i]});
        }
        sort(temp.begin(),temp.end());
        vector<int> res;
        for(auto it : temp){
            res.push_back(it.second);
        }
        return res;
    }
};