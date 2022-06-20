class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> m;
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto it : m){
            pq.push({it.second,it.first});
        }
        string res="";
        while(pq.size()>1){
            auto temp1 = pq.top();
            pq.pop();
            auto temp2 = pq.top();
            pq.pop();
            temp2.first--;
            temp1.first--;
            res+=temp1.second;
            res+=temp2.second;
            if(temp2.first!=0){
                pq.push(temp2);
            }
            if(temp1.first!=0){
                pq.push(temp1);
            }
        }
        if(!pq.empty()){
            for(int i=0;i<pq.top().first;i++){
                res+=pq.top().second;
            }
        }
        for(int i=1;i<res.size();i++){
            if(res[i]==res[i-1]){
                return "";
            }
        }
        return res;
        
        
    }
};