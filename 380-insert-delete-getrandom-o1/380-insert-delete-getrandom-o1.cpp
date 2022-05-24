class RandomizedSet {
public:
    unordered_set<int> se;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(se.find(val)==se.end()){
            se.insert(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(se.find(val)!=se.end()){
            se.erase(val);
            return true;
        }
        return false;
        
    }
    
    int getRandom() {
        int size = se.size();
        int random = rand() % size;            
        auto it = se.begin();
        std::advance(it, random);
        return *it;
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */