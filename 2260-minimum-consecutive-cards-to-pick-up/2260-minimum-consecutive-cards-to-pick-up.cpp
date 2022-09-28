class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> m;
        int res = INT_MAX;
        for(int i=0;i<cards.size();i++){
            if(m.find(cards[i])!=m.end()){
                res=min(res, (i-m[cards[i]])+1);
            }
            m[cards[i]]=i;
        }
        return res==INT_MAX?-1:res;
        
    }
};