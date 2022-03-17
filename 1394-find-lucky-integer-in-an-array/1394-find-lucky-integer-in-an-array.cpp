class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int, int> m;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        }
        int max=-1;
        for(auto it:m){
            if(it.first == it.second && it.first > max){
                max=it.first;
            }
        }
        return max;
        
    }
};