class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        map<int, int> m;
        for(int i=0;i<n;i++){
            m[hand[i]]++;
        }
        while(m.size()>=groupSize){
            auto i=m.begin();
            int v=i->first;
            m[v]--;
            if(m[v]==0){
                m.erase(v);
            }
            for(int i=1;i<=groupSize-1;i++){
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