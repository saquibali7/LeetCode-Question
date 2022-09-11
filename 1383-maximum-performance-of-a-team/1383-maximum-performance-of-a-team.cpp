class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        long long int mod = pow(10,9)+7;
        long long int res=0;
        long long int sum=0;
        vector<pair<int, int>> temp;
        for(int i=0;i<n;i++){
            temp.push_back({efficiency[i], speed[i]});
        }
        sort(temp.begin(), temp.end(), greater<pair<int,int>>());
        priority_queue<int,vector<int>, greater<int>> pq;
        for(int i=0;i<n;i++){
            int s = temp[i].second;
            int e = temp[i].first;
            sum+=s;
            pq.push(s);
            if(pq.size() > k){
                int temp1 = pq.top();
                pq.pop();
                sum-=temp1;
            }
            res = max(res, sum*e);
        }
        return res%mod;
        
    }
};