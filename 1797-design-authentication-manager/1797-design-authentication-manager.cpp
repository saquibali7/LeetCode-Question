class AuthenticationManager {
public:
    unordered_map<string, int> m;
    int time;
    AuthenticationManager(int timeToLive) {
        time = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        m[tokenId]=currentTime+time;
    }
    
    void renew(string tokenId, int currentTime) {
        if(m[tokenId] > currentTime){
            m[tokenId]=currentTime+time;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int count=0;
        for(auto i : m){
            if(i.second > currentTime){
                count++;
            }
        }
        return count;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */