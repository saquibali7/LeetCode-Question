class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> se;
        for(int i=0;i<jewels.length();i++){
            se.insert(jewels[i]);
        }
        int count=0;
        for(int i=0;i<stones.length();i++){
            if(se.find(stones[i])!=se.end()){
                count++;
            }
        }
        return count;
    }
};