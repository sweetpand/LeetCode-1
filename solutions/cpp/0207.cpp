class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    vector<int> state(numCourses, 0);  // 0: init, 1: visiting, 2: visited

    for (const vector<int>& p : prerequisites)
      graph[p[1]].push_back(p[0]);

    function<bool(int)> hasCycle = [&](int course) {
      if (state[course] == 1) return true;
      if (state[course] == 2) return false;

      state[course] = 1;
      for (int neighbor : graph[course])
        if (hasCycle(neighbor))
          return true;
      state[course] = 2;

      return false;
    };

    for (int course = 0; course < numCourses; ++course)
      if (hasCycle(course))
        return false;

    return true;
  }
};