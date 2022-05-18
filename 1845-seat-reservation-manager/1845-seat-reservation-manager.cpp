class SeatManager {
public:
    unordered_set<int> m;
    priority_queue<int,vector<int>,greater<int>> pq;
    int count=0;
    SeatManager(int n) {
    }
    
    int reserve() {
        if(!pq.empty()){
            m.insert(pq.top());
            int temp=pq.top();
            pq.pop();
            return temp;
        }
        else {
            count++;
            m.insert(count);
            return count;
        }
        
    }
    
    void unreserve(int seatNumber) {
        m.erase(seatNumber);
        pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */