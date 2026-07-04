class Twitter {
public:
    struct Tweet {
        int tweetId;
        int time;
        Tweet(int id, int t) : tweetId(id), time(t) {};
    };
    struct comp {
    public:
        bool operator()(const Tweet& a, Tweet& b) {
            return a.time > b.time; // minHeap by time
        }
    };
    int time;
    unordered_map<int, vector<Tweet>> tweets;
    unordered_map<int, unordered_set<int>> following;

    Twitter() { time = 0; }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back(Tweet(tweetId, time++));
    }

    vector<int> getNewsFeed(int userId) {
        // min heap top 10
        priority_queue<Tweet, vector<Tweet>, comp> minHeap;
        
        following[userId].insert(userId);
        if (following.find(userId) != following.end()) {
            for (auto f : following[userId]) {
                if (tweets.find(f) != tweets.end()) {
                    for (auto t : tweets[f]) {
                        minHeap.push(t);
                        if (minHeap.size() > 10) {
                            minHeap.pop(); // oldest tweet remove
                        }
                    }
                }
            }
        }
        vector<int>ans;
        while(!minHeap.empty()){
            ans.push_back(minHeap.top().tweetId);
            minHeap.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

    void follow(int followerId, int followeeId) {

        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (following.find(followerId) != following.end()) {
            following[followerId].erase(followeeId);
        }
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