struct Tweet {
  int tweetId;
  int time;
  Tweet(int tweetId, int time) : tweetId(tweetId), time(time) {}
};

class Twitter {
 public:
  void postTweet(int userId, int tweetId) {
    tweets[userId].push_back(Tweet(tweetId, time++));
  }

  vector<int> getNewsFeed(int userId) {
    vector<int> newsFeed;

    auto compare = [](const Tweet& a, const Tweet& b) {
      return a.time < b.time;
    };
    priority_queue<Tweet, vector<Tweet>, decltype(compare)> pq(compare);

    // push your own tweets
    for (const Tweet& tweet : tweets[userId])
      pq.push(tweet);

    // push your followees' tweets
    for (const int followeeId : followees[userId])
      for (const Tweet& tweet : tweets[followeeId])
        pq.push(tweet);

    for (int i = min(10, (int)pq.size()); i > 0; --i)
      newsFeed.push_back(pq.top().tweetId), pq.pop();

    return newsFeed;
  }

  void follow(int followerId, int followeeId) {
    if (followerId == followeeId) return;
    followees[followerId].insert(followeeId);
  }

  void unfollow(int followerId, int followeeId) {
    if (followerId == followeeId) return;
    followees[followerId].erase(followeeId);
  }

 private:
  int time = 0;
  unordered_map<int, unordered_set<int>> followees;  // {userId: {followeeIds}}
  unordered_map<int, vector<Tweet>> tweets;          // {userId: {Tweets}}
};