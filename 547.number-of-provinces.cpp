/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] Number of Provinces
 */

#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
private:
  class DisjointSet {
  private:
    vector<int> data;

  public:
    size_t count;
    DisjointSet(size_t n, size_t c) : count{c} {
      data.resize(n);

      for (int i = 0; i < n; ++i) {
        data[i] = i;
      }
    }

    int root(int i) {
      while (i != data[i]) {
        data[i] = data[data[i]];
        i = data[i];
      }
      return i;
    }

    void connect(int i, int j) {
      int rootI = root(i);
      int rootJ = root(j);

      if (rootI != rootJ) {
        data[rootI] = rootJ;
        count--;
      }
    }
  };

  void dfsSolutionHelper(vector<vector<int>> &isConnected, int i,
                         vector<bool> &isVisited) {
    for (int j = 0; j < isConnected.size(); ++j) {
      if (isConnected[i][j] == 1 && !isVisited[j]) {
        isVisited[j] = true;
        dfsSolutionHelper(isConnected, j, isVisited);
      }
    }
  }

public:
  /**
   * @brief This question could be abstracted into getting
   * the number of connected component in a graph.
   *
   */
  int dfsSolution(vector<vector<int>> &isConnected) {
    int n = isConnected.size();

    vector<bool> isVisited(n);
    fill(isVisited.begin(), isVisited.end(), false);

    int provinces = 0;

    for (int i = 0; i < n; ++i) {
      if (!isVisited[i]) {
        dfsSolutionHelper(isConnected, i, isVisited);
        provinces++;
      }
    }

    return provinces;
  }

  int unionFindSolution(vector<vector<int>> &isConnected) {
    DisjointSet set{isConnected.size(), isConnected.size()};

    for (int i = 0; i < isConnected.size(); ++i) {
      for (int j = i + 1; j < isConnected.size(); ++j) {
        if (isConnected[i][j] == 1) {
          set.connect(i, j);
        }
      }
    }

    return set.count;
  }

  int findCircleNum(vector<vector<int>> &isConnected) {
    // return dfsSolution(isConnected);
    return unionFindSolution(isConnected);
  }
};
// @lc code=end
