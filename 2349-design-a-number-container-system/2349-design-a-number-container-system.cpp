class NumberContainers {
public:
    unordered_map<int, set<int>> m;
    unordered_map<int, int> m1;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        m1[index]=number;
        m[number].insert(index);
    }
    
    int find(int number) {
        for(auto i : m[number]){
            if(m1[i]==number){
                return i;
            }
        }
        return -1;
        
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */