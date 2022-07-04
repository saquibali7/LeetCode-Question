class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n=nums.size();
        map<int, int> m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        while(m.size()>=k){
            auto i=m.begin();
            int v=i->first;
            m[v]--;
            if(m[v]==0){
                m.erase(v);
            }
            for(int i=1;i<=k-1;i++){
                if(m.find(v+i)!=m.end()){
                    m[v+i]--;
                    if(m[v+i]==0){
                        m.erase(v+i);
                    }
                } else {
                    return false;
                }
            }
        }
        if(m.size()==0){
            return true;
        }
        return false; 
    }
};