class Solution {
public:
    int minDeletions(string s) {
        int n=s.size();
        unordered_map<char,int> m;
        for(int i=0;i<n;i++){
            m[s[i]]++;
        }
        vector<int> temp;
        for(auto it : m){
            temp.push_back(it.second);
        }
        sort(temp.begin(),temp.end());
        unordered_set<int> se;
        int count=0;
        for(int i=0;i<temp.size();i++){
            if(se.find(temp[i])==se.end()){
                se.insert(temp[i]);
            } else {
                while(se.find(temp[i])!=se.end() && temp[i]>0){
                    temp[i]--;
                    count++;
                }
                if(temp[i]>=0){
                    se.insert(temp[i]);
                }
            }
        }
        return count;
    }
};