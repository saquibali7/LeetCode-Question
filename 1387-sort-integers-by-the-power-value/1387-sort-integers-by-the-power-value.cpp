class Solution {
public:
    int power(int a){
        int count=0;
        while(a!=1){
            if(a%2==0){
                a/=2;
                count++;
            } else {
                a=a*3+1;
                count++;
            }
        }
        return count;
    }
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>> res;
        unordered_map<int, int> m;
        for(int i=lo;i<=hi;i++){
            res.push_back({power(i),i});
        }
        sort(res.begin(),res.end());
        return res[k-1].second;
        
    }
};