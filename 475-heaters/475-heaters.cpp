class Solution {
public:
    static bool mycmp(pair<int, int> a, pair<int, int> b){
        return a.first<b.first;
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        vector<pair<int,int>> temp;
        int n=houses.size(),m=heaters.size();
        for(int i=0;i<n;i++){
            temp.push_back({houses[i],0});
        }
        for(int i=0;i<m;i++){
            temp.push_back({heaters[i],1});
        }
        sort(temp.begin(),temp.end(),mycmp);
        int res=INT_MIN;
        for(int i=0;i<temp.size();i++){
            if(temp[i].second==0){
                int curr=INT_MAX;
                int j=i;
                while(temp[j].second!=1 && j>0){
                    j--;
                }
                if(temp[j].second==1){
                    curr = min(curr,abs(temp[j].first-temp[i].first));
                }
                j=i;
                while(temp[j].second!=1 && j<m+n-1){
                    j++;
                }
                if(temp[j].second==1){
                    curr = min(curr,abs(temp[j].first-temp[i].first));
                }
                res = max(res, curr);
            }
        }
        return res;
    }
};