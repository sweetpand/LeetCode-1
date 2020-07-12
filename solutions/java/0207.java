class Solution {
  public boolean canFinish(int numCourses, int[][] prerequisites) {
    List<Integer>[] graph = new List[numCourses];
    for (int course = 0; course < numCourses; ++course)
      graph[course] = new ArrayList<>();

    int[] state = new int[numCourses];

    for (final int[] p : prerequisites)
      graph[p[1]].add(p[0]);

    for (int course = 0; course < numCourses; ++course)
      if (hasCycle(course, graph, state))
        return false;

    return true;
  }

  boolean hasCycle(int course, List<Integer>[] graph, int[] state) {
    if (state[course] == 1)
      return true;
    if (state[course] == 2)
      return false;

    state[course] = 1;
    for (int neighbor : graph[course])
      if (hasCycle(neighbor, graph, state))
        return true;
    state[course] = 2;

    return false;
  }
}