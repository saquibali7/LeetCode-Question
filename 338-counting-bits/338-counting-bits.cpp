class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        int temp=0;
        res.push_back(0);
        for(int i=1;i<=n;i++){
            temp = (i&1) + res[i/2];
            res.push_back(temp);
        }
        return res;
    }
};