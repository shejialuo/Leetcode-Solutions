/*
 * @lc app=leetcode.cn id=1519 lang=cpp
 *
 * [1519] Number of Nodes in the Sub-Tree With the Same Label
 */

#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

// @lc code=start
class Solution {

private:
  vector<vector<int>> info{};

  void countSubTreesHelper(int index, vector<vector<int>> &adjacent,
                           string &labels, vector<int> &ans,
                           vector<bool> &isVisited) {

    isVisited[index] = true;

    for (auto &&next : adjacent[index]) {
      if (!isVisited[next]) {

        countSubTreesHelper(next, adjacent, labels, ans, isVisited);
        for (int i = 0; i < 26; i++) {
          info[index][i] += info[next][i];
        }
      }
    }
    char label = labels[index];
    info[index][label - 'a']++;

    ans[index] = info[index][label - 'a'];
  }

public:
  vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels) {
    vector<int> ans(n, 0);

    vector<vector<int>> adjacent(n);

    vector<bool> isVisited(n, false);

    info.resize(n, vector<int>(26, 0));

    for (auto &&edge : edges) {
      adjacent[edge[0]].push_back(edge[1]);
      adjacent[edge[1]].push_back(edge[0]);
    }

    countSubTreesHelper(0, adjacent, labels, ans, isVisited);

    return ans;
  }
};
// @lc code=end
