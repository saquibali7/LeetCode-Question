class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        string res[5] = {"Flush", "Three of a Kind", "Pair", "High Card"};
        unordered_map<char, int> m1;
        unordered_map<int, int> m2;
        for(int i=0;i<5;i++){
            m1[suits[i]]++;
            m2[ranks[i]]++;
        }
        for(auto i : m1){
            if(i.second == 5){
                return res[0];
            }
        }
        for(auto i : m2){
            if(i.second >= 3){
                return res[1];
            }
        }
        for(auto i : m2){
            if(i.second >= 2){
                return res[2];
            }
        }
        return res[3];
        
    }
};