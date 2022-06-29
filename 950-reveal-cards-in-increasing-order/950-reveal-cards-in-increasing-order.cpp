class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n=deck.size();
        sort(deck.begin(),deck.end());
        vector<int> res;
        queue<int> q;
        q.push(deck[n-1]);
        for(int i=n-2;i>=0;i--){
            int temp=q.front();
            q.pop();
            q.push(temp);
            q.push(deck[i]);
        }
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
};