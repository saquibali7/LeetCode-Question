class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> res;
        sort(arr.begin(),arr.end());
        int min_diff=abs(arr[1]-arr[0]);
        for(int i=1;i<n;i++){
            min_diff = min(min_diff,arr[i]-arr[i-1]);
        }
        for(int i=1;i<n;i++){
            if(arr[i]-arr[i-1]==min_diff){
                vector<int> temp;
                temp.push_back(arr[i-1]);
                temp.push_back(arr[i]);
                res.push_back(temp);
            }
        }
        return res;
    }
};