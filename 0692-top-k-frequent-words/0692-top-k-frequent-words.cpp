class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n=words.size();
        map<string, int> m;
        for(int i=0;i<n;i++){
            m[words[i]]++;
        }
        vector<string> res;
        for(int i=0;i<k;i++){
            int max=-1;
            string temp="";
            for(auto it : m){
                if(it.second > max){
                    max=it.second;
                    temp=it.first;
                }
            }
            res.push_back(temp);
            m.erase(temp);
        }
        return res;
        
        
    }
};