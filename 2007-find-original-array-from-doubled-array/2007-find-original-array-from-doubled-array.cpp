class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n=changed.size();
        map<int,int> s;
        vector<int> res;
        for(auto i : changed){
            s[i]++;
        }
        while(!s.empty()){
            auto it=s.begin();
            int i=it->first;
            s[i]--;
            if(s[i]==0){
                s.erase(i);
            }
            if(s.find(2*i)==s.end()){
                return{};
            } else {
                res.push_back(i);
                s[2*i]--;
                if(s[2*i]==0){
                    s.erase(2*i);
                }
            }
            
        }
        if(res.size()==n/2){
            return res;
        }
        return {};
        
    }
};