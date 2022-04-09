class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> pq;
        int n=arr.size();
        for(int i=0;i<k;i++){
            pq.push({abs(arr[i]-x),i});
        }
        for(int i=k;i<n;i++){
            int diff = abs(arr[i]-x);
            if(diff < pq.top().first){
                pq.pop();
                pq.push({diff,i});
            }
        }
        vector<int> res;
        while(pq.size()>0){
            res.push_back(arr[pq.top().second]);
            pq.pop();
        }
        sort(res.begin(),res.end());
        return res;
        
        
    }
};