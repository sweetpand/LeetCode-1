class RandomizedCollection {
  public boolean insert(int val) {
    if (!map.containsKey(val))
      map.put(val, new LinkedHashSet<>());
    map.get(val).add(vals.size());
    vals.add(val);
    return map.get(val).size() == 1;
  }

  public boolean remove(int val) {
    if (!map.containsKey(val) || map.get(val).isEmpty())
      return false;
    int index = map.get(val).iterator().next();
    int lastVal = vals.get(vals.size() - 1);
    vals.set(index, lastVal);
    vals.remove(vals.size() - 1);
    map.get(val).remove(index);
    map.get(lastVal).add(index);
    map.get(lastVal).remove(vals.size());
    return true;
  }

  public int getRandom() {
    int index = rand.nextInt(vals.size());
    return vals.get(index);
  }

  private List<Integer> vals = new ArrayList<>();
  private Map<Integer, LinkedHashSet<Integer>> map = new HashMap<>();
  private Random rand = new Random();
}