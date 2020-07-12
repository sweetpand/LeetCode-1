class RandomizedSet {
  public boolean insert(int val) {
    if (map.containsKey(val))
      return false;
    map.put(val, vals.size());
    vals.add(val);
    return true;
  }

  public boolean remove(int val) {
    if (!map.containsKey(val))
      return false;
    int index = map.get(val);
    map.put(vals.get(vals.size() - 1), index);
    map.remove(val);
    vals.set(index, vals.get(vals.size() - 1));
    vals.remove(vals.size() - 1);
    return true;
  }

  public int getRandom() {
    int index = rand.nextInt(vals.size());
    return vals.get(index);
  }

  private List<Integer> vals = new ArrayList<>();
  private Map<Integer, Integer> map = new HashMap<>();
  private Random rand = new Random();
}