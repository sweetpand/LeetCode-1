class Twitter {
  public void postTweet(int userId, int tweetId) {
    if (!tweets.containsKey(userId))
      tweets.put(userId, new LinkedList<>());
    tweets.get(userId).addFirst(new Pair<>(timer++, tweetId));
    if (tweets.get(userId).size() > 10)
      tweets.get(userId).removeLast();
  }

  public List<Integer> getNewsFeed(int userId) {
    List<Integer> ans = new ArrayList<>();
    Queue<Pair<Integer, Integer>> pq = new PriorityQueue<>((t1, t2) -> t2.getKey() - t1.getKey());
    for (Pair<Integer, Integer> tweet : tweets.getOrDefault(userId, new LinkedList<>()))
      pq.add(tweet);
    for (Integer followee : followees.getOrDefault(userId, new HashSet<>()))
      for (Pair<Integer, Integer> tweet : tweets.getOrDefault(followee, new LinkedList<>()))
        pq.add(tweet);
    for (int i = Math.min(10, pq.size()); i > 0; --i)
      ans.add(pq.poll().getValue());
    return ans;
  }

  public void follow(int followerId, int followeeId) {
    if (followerId == followeeId)
      return;
    if (!followees.containsKey(followerId))
      followees.put(followerId, new HashSet<>());
    followees.get(followerId).add(followeeId);
  }

  public void unfollow(int followerId, int followeeId) {
    if (followerId == followeeId)
      return;
    if (followees.containsKey(followerId))
      if (followees.get(followerId).contains(followeeId))
        followees.get(followerId).remove(followeeId);
  }

  private int timer = 0;
  private Map<Integer, Deque<Pair<Integer, Integer>>> tweets = new HashMap<>();
  private Map<Integer, Set<Integer>> followees = new HashMap<>();
}