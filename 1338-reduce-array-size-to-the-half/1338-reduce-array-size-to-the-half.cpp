class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        }
        priority_queue<int> pq;
        for( auto it : m) {
            pq.push(it.second);
        }
        int count=0,res=0;
        while(pq.size() > 0){
            count++;
            res+=pq.top();
            if(res>=n/2){
                return count;
            }
            pq.pop();
        }
        return -1;
    }
};