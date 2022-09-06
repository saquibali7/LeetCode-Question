class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char, int> m;
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
        }
        priority_queue<pair<char, int>> pq;
        for(auto i : m){
            pq.push({i.first, i.second});
        }
        string res="";
        int count=0;
        while(!pq.empty()){
            if(count<repeatLimit){
                auto temp=pq.top();
                pq.pop();
                res+=temp.first;
                temp.second--;
                if(temp.second!=0){
                    pq.push(temp);
                    count++;
                } else {
                    count=0;
                }
            } else if(pq.size() > 1) {
                auto temp=pq.top();
                pq.pop();
                auto temp1=pq.top();
                pq.pop();
                res+=temp1.first;
                temp1.second--;
                if(temp1.second!=0){
                    pq.push(temp1);
                }
                count=0;
                pq.push(temp);
            } else if(pq.size()==1){
                break;
            }
        }
        return res;
    }
};