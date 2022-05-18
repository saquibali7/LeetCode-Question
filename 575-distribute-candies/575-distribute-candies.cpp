class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n=candyType.size();
        unordered_set<int> se;
        for(int i=0;i<n;i++){
            se.insert(candyType[i]);
        }
        if(se.size()<=n/2){
            return se.size();
        }
        return n/2;
    }
};