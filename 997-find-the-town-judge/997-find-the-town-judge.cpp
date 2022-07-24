class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if( n==1 && trust.size()==0){
            return 1;
        }
        unordered_map<int, int> m;
        unordered_map<int,int> m1;
        for(int i=1;i<=n;i++){
            m[i]=0;
        }
        for(int i=0;i<trust.size();i++){
            m[trust[i][0]]=trust[i][1];
            m1[trust[i][1]]++;
        }
        for(auto i : m1){
            if(i.second==n-1 && m[i.first]==0){
                return i.first;
            }
        }
        return -1;
        
        
    }
};