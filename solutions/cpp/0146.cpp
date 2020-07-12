class LRUCache {
 public:
  LRUCache(int capacity) : capacity(capacity) {}

  int get(int key) {
    if (!keyToIterator.count(key)) return -1;

    const auto& it = keyToIterator[key];
    cache.splice(begin(cache), cache, it);
    return it->value;
  }

  void put(int key, int value) {
    if (keyToIterator.count(key)) {
      const auto& it = keyToIterator[key];
      cache.splice(begin(cache), cache, it);
      it->value = value;
      return;
    }

    if (cache.size() == capacity) {
      const Node& lastNode = cache.back();
      keyToIterator.erase(lastNode.key);
      cache.pop_back();
    }

    cache.push_front({key, value});
    keyToIterator[key] = begin(cache);
  }

 private:
  struct Node {
    int key;
    int value;
  };

  unordered_map<int, list<Node>::iterator> keyToIterator;
  list<Node> cache;
  int capacity;
};