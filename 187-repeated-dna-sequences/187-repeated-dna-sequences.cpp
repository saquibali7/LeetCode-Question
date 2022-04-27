class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.length();
        unordered_map<string,int> m;
        vector<string> res;
        int count=0;
        for(int i=0;i<n-9;i++){
            string temp=s.substr(i,10);
            if(temp.length()==10){
                m[temp]++;
            }
            
        }
        for(auto it : m){
            if(it.second > 1){
                res.push_back(it.first);
            }
        }
        
        return res;
    }
};