class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long> res;
        long long temp = num/3;
        if((temp-1)+temp+(temp+1)==num){
            res.push_back(temp-1);
            res.push_back(temp);
            res.push_back(temp+1);
        }
        return res;
    }
};