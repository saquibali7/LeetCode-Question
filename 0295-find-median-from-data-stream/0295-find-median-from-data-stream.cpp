class MedianFinder {
public:
    priority_queue<int> pq1;
    priority_queue<int,vector<int>,greater<int>> pq2;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(pq1.empty() && pq2.empty()){
            pq1.push(num);
        } else if(pq1.size() > pq2.size()){
            if(pq1.top() > num){
                pq2.push(pq1.top());
                pq1.pop();
                pq1.push(num);
            } else {
                pq2.push(num);
            }
        }
        else {
            if(num<=pq1.top()){
                pq1.push(num);
            } else {
                pq2.push(num);
                pq1.push(pq2.top());
                pq2.pop();
            }
        }
    }
    
    double findMedian() {
        if(pq1.size()==pq2.size()){
            int temp = (pq1.top()+ pq2.top());
            double res= double(temp)/2;
            return res;
        }
        return pq1.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */