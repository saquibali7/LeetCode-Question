class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int,int> m;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        }
        for(auto it : m){
            pq.push(it.second);
        }
        for(int i=0;i<k;i++){
            int temp=pq.top();
            temp--;
            pq.pop();
            if(temp!=0){
                pq.push(temp);
            }
        }
        return pq.size();
    }
};