class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);
        int res=0;
        while(pq.size() > 1){
            int temp1=pq.top();
            pq.pop();
            int temp2=pq.top();
            pq.pop();
            temp1--;
            temp2--;
            if(temp1 > 0){
                pq.push(temp1);
            }
            if(temp2 > 0){
                pq.push(temp2);
            }
            res++;
        }
        return res;
    }
};