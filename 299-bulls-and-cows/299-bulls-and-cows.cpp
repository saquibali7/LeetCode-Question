class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> m;
        for(auto i : secret){
            m[i]++;
        }
        unordered_set<int> se;
        int bulls=0,cows=0;
        for(int i=0;i<guess.length();i++){
            if(guess[i]==secret[i]){
                m[secret[i]]--;
                if(m[secret[i]]==0){
                    m.erase(secret[i]);
                }
                bulls++;
                se.insert(i);
            }
        }
        for(int i=0;i<guess.length();i++){
            if(se.find(i)!=se.end()){
                continue;
            }
            if(m.find(guess[i])!=m.end()){
                cows++;
                m[guess[i]]--;
                if(m[guess[i]]==0){
                    m.erase(guess[i]);
                }
            }
        }
        string res=to_string(bulls)+"A"+to_string(cows)+"B";
        return res;
        
    }
};