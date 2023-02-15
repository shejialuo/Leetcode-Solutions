/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] Redundant Connection
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
private:
  class DisjointSet {
  private:
    vector<int> data;

  public:
    DisjointSet(size_t n) {
      data.resize(n + 1);
      for (int i = 0; i <= n; ++i) {
        data[i] = i;
      }
    }

    int root(int i) {
      while (data[i] != i) {
        data[i] = data[data[i]];
        i = data[i];
      }
      return i;
    }

    void connect(int i, int j) {
      int rootI = root(i);
      int rootJ = root(j);
      data[rootI] = rootJ;
    }

    bool isConnect(int i, int j) { return root(i) == root(j); }
  };

public:
  vector<int> findRedundantConnection(vector<vector<int>> &edges) {
    DisjointSet set{edges.size()};
    int indexI = -1, indexJ = -1;
    for (auto &&edge : edges) {
      int i = edge[0];
      int j = edge[1];
      if (set.isConnect(i, j)) {
        indexI = i;
        indexJ = j;
      } else {
        set.connect(i, j);
      }
    }

    if (indexI == -1) {
      return {};
    }

    return vector<int>{indexI, indexJ};
  }
};
// @lc code=end
