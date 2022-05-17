class MapSum {
public:
    unordered_map<string, int>m;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        if(m.find(key)!=m.end()){
            m.erase(key);
            m.insert({key,val});
        } else if(m.find(key)==m.end()){
            m.insert({key,val});
        }
        
    }
    
    int sum(string prefix) {
        int sum=0;
        for(auto it : m){
            bool flag=false;
            for(int i=0;i<prefix.length();i++){
                if(prefix[i]!=it.first[i]){
                    flag=true;
                    break;
                }
            }
            if(!flag){
                sum+=it.second;
            }
        }
        return sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */