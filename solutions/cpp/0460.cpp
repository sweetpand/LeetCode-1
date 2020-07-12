class LFUCache {
 public:
  LFUCache(int capacity) : capacity(capacity), minFreq(0) {}

  int get(int key) {
    if (!keyToNode.count(key)) return -1;

    Node& node = keyToNode[key];
    touch(node);
    return node.value;
  }

  void put(int key, int value) {
    if (capacity == 0) return;

    if (keyToNode.count(key)) {
      Node& node = keyToNode[key];
      node.value = value;
      touch(node);
      return;
    }

    if (keyToNode.size() == capacity) {
      // remove the key:
      //  1. minimum frequency
      //  2. LRU if there are multiple nodes w/ the same frequency
      const int keyToEvict = freqToList[minFreq].back();
      freqToList[minFreq].pop_back();
      keyToNode.erase(keyToEvict);
    }

    const int freq = 1;
    minFreq = freq;
    freqToList[freq].push_front(key);
    keyToNode[key] = {key, value, freq, cbegin(freqToList[freq])};
  }

 private:
  struct Node {
    int key;
    int value;
    int freq;
    list<int>::const_iterator it;
  };

  void touch(Node& node) {
    // update the node's frequency
    const int prevFreq = node.freq;
    const int newFreq = ++node.freq;

    // remove the iterator from prevFreq's list
    freqToList[prevFreq].erase(node.it);
    if (freqToList[prevFreq].empty()) {
      freqToList.erase(prevFreq);
      // update minFreq if needed
      if (prevFreq == minFreq) ++minFreq;
    }

    // insert the key to the front of newFreq's list
    freqToList[newFreq].push_front(node.key);
    node.it = cbegin(freqToList[newFreq]);
  }

  unordered_map<int, Node> keyToNode;
  unordered_map<int, list<int>> freqToList;
  int capacity;
  int minFreq;
};