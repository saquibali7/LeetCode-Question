class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> res;
        if(n==1){
            return res;
        }
        int dr=2;
        while(dr<=n){
            int nr=1;
            while(nr<dr){
                if(__gcd(nr,dr)!=1){
                    nr++;
                    continue;
                }
                string temp = to_string(nr)+"/"+to_string(dr);
                res.push_back(temp);
                nr++;
            }
            dr++;
        }
        return res;
        
    }
};