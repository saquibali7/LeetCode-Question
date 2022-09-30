class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int n=spells.size(), m = potions.size();
        vector<int> res;
        for(int i=0;i<n;i++){
            int low = 0, high = m-1, mid;
            while(low<=high){
                mid = (low+high)/2;
                if((long long)potions[mid]*spells[i]>=success){
                    high = mid-1;
                }
                else if((long long)potions[mid]*spells[i]<success) {
                    low = mid+1;
                }
            }
            res.push_back(m-low);
        }
        return res;
    }
};