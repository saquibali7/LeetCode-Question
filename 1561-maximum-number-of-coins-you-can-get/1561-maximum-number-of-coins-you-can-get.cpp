class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n=piles.size();
        int count = n/3;
        sort(piles.begin(),piles.end());
        int count1=0;
        int res=0,i=n-2;
        while(count1<count){
            count1++;
            res+=piles[i];
            i=i-2;
        }
        return res;
    }
};