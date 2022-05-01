class Solution {
public:
    struct mycmp{
        bool operator()(pair<int,int> &a, pair<int, int> &b){
            return a.first+a.second < b.first+b.second;
        }
    };
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size(),m=nums2.size();
        vector<vector<int>> res;
        priority_queue<pair<int,int>,vector<pair<int, int>>, mycmp> pq;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pq.size()>=k && nums1[i]+nums2[j]>pq.top().first+pq.top().second){
                    break;
                }
                else if(pq.size()>=k && nums1[i]+nums2[j]<=pq.top().first+pq.top().second){
                    pq.pop();
                    pq.push({nums1[i],nums2[j]});
                } else if(pq.size()<k) {
                    pq.push({nums1[i],nums2[j]});
                }
            }
        }
        while(pq.empty()==false){
            vector<int> temp;
            temp.push_back(pq.top().first);
            temp.push_back(pq.top().second);
            res.push_back(temp);
            pq.pop();
        }
        return res;
    }
};