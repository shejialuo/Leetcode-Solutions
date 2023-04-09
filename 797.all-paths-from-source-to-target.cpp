/*
 * @lc app=leetcode.cn id=797 lang=cpp
 *
 * [797] All Paths From Source to Target
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
private:
  void allPathsSourceTargetHelper(int node, vector<vector<int>> &graph,
                                  vector<vector<int>> &ans, vector<int> &path) {
    if (node == graph.size() - 1) {
      ans.push_back(path);
      return;
    }

    auto &&neighbors = graph[node];

    for (auto &&neighbor : neighbors) {
      path.push_back(neighbor);
      allPathsSourceTargetHelper(neighbor, graph, ans, path);
      path.pop_back();
    }
  }

public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
    vector<vector<int>> ans{};
    vector<int> path{};

    path.push_back(0);
    allPathsSourceTargetHelper(0, graph, ans, path);

    return ans;
  }
};
// @lc code=end
