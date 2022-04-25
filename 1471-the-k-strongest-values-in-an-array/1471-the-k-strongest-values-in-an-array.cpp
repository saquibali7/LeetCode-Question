class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> res;
        if(n==1){
            return arr;
        }
        priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        sort(arr.begin(),arr.end());
        int median=arr[(n-1)/2];
        for(int i=0;i<k;i++){
            pq.push({abs(arr[i]-median),arr[i]});
        }
        for(int i=k;i<n;i++){
            if(abs(arr[i]-median) > pq.top().first){
                pq.pop();
                pq.push({abs(arr[i]-median),arr[i]});
            } else if(abs(arr[i]-median)==pq.top().first && arr[i]>pq.top().second){
                pq.pop();
                pq.push({abs(arr[i]-median),arr[i]});
            }
        }
        while(pq.size() > 0){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
        
    }
};