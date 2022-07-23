class Twitter {
public:
    unordered_map<int,unordered_set<int>> friends;
    priority_queue<int, vector<int> , greater<int>> pq;
    vector<pair<int, int>> twt;
    int count=0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        twt.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        int n=twt.size();
        vector<int> res;
        for(int i=n-1;i>=0;i--){
            if((twt[i].first == userId || 
               friends[userId].find(twt[i].first)!=friends[userId].end())
               && res.size() < 10){
                res.push_back(twt[i].second);
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        friends[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        friends[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */