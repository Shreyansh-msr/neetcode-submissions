class Twitter {
private:
    unordered_map<int, vector<array<int, 2>>> tweetMap; // userId -> [{timestamp, tweetId}, ...]
    unordered_map<int, unordered_set<int>> followerMap; // followerId -> set of followeeIds
    int timestamp = 0;

public:
    Twitter() {
        tweetMap.clear();
        followerMap.clear();
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back(array<int, 2>{++timestamp, tweetId});  
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        priority_queue<array<int, 4>> maxHeap; 
        followerMap[userId].insert(userId); // Ensure user sees their own tweets

        for (int followeeId : followerMap[userId]) {
            if (tweetMap.count(followeeId) && !tweetMap[followeeId].empty()) {
                int index = tweetMap[followeeId].size() - 1;
                // {timestamp, tweetId, followeeId, index}
                maxHeap.push(array<int, 4>{
                    tweetMap[followeeId][index][0], 
                    tweetMap[followeeId][index][1], 
                    followeeId, 
                    index
                });
            }
        }
        
        while (!maxHeap.empty() && res.size() < 10) {
            auto curr = maxHeap.top();
            maxHeap.pop();

            res.push_back(curr[1]); // Append tweetId
            int index = curr[3];

            if (index > 0) {
                const auto& tweet = tweetMap[curr[2]][index - 1];
                maxHeap.push(array<int, 4>{tweet[0], tweet[1], curr[2], index - 1});
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            followerMap[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        followerMap[followerId].erase(followeeId);
    }
};