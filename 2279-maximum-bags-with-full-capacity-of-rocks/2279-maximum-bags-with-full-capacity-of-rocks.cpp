class Solution {
public:
    static bool mycmp(pair<int,int> a, pair<int, int> b){
        return (a.second-a.first) < (b.second-b.first);
    }
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<pair<int,int>> temp;
        int n=rocks.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(rocks[i]==capacity[i]){
                count++;
                continue;
            }
            temp.push_back({rocks[i],capacity[i]});
        }
        int a=additionalRocks;
        sort(temp.begin(),temp.end(),mycmp);
        for(int i=0;i<temp.size();i++){
            if((temp[i].second-temp[i].first)<=a){
                a-=(temp[i].second-temp[i].first);
                count++;
            }
            if(a==0){
                break;
            }
        }
        return count;
        
    }
};