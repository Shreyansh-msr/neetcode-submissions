class Twitter {
private:
    unordered_map <int, vector<int>> tweetMap; //<userId, tweetId>
    unordered_map<int, unordered_set<int>> followerMap;
    int timestamp = 0;
    unordered_map<int, int> tweetTime;

public:
    Twitter() {
        tweetMap = {};
        followerMap = {};
        tweetTime = {};
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back(tweetId);  
        tweetTime[tweetId] = ++timestamp;
    }
    
    vector<int> getNewsFeed(int userId) {
     
        auto cmp = [this](int a, int b) {
            return tweetTime[a] < tweetTime[b];
        };
        priority_queue<int, std::vector<int>, decltype(cmp)> maxHeap(cmp);

        for(int tweetId : tweetMap[userId]) maxHeap.push(tweetId);
        
        for(int followeeId : followerMap[userId]) for(int tweetId : tweetMap[followeeId]) maxHeap.push(tweetId);

        vector<int> tweets = {};
        int i=1;
        while(i<=10 && !maxHeap.empty())
        {
            tweets.push_back(maxHeap.top());
            maxHeap.pop();
            i++;
        }
        return tweets;

    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId) followerMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followerMap[followerId].erase(followeeId);
    }

    void printUserTweets(int userId)
    {
        vector<int> tweets = getNewsFeed(userId);   
        for(int tweetId : tweets) cout << tweetId <<" ";
        cout<< '\n';
    }
};