class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        if(barcodes.size()==1){
            return barcodes;
        }
        unordered_map<int, int> m;
        for(int i=0;i<barcodes.size();i++){
            m[barcodes[i]]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto it : m){
            pq.push({it.second,it.first});
        }
        vector<int> res;
        while(pq.size()>1){
            auto temp1=pq.top();
            pq.pop();
            auto temp2 = pq.top();
            pq.pop();
            res.push_back(temp1.second);
            res.push_back(temp2.second);
            temp1.first--;
            temp2.first--;
            if(temp1.first!=0){
                pq.push(temp1);
            }
            if(temp2.first!=0){
                pq.push(temp2);
            }
        }
        if(pq.size()==1){
            res.push_back(pq.top().second);
        }
        return res;
    }
};