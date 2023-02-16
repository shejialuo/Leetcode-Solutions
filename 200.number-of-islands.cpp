/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] Number of Islands
 */

#include <vector>
using namespace std;

/**
 * This is a very interesting problem. We could solve it with dfs, when we
 * encounter a new '1', we add the counter and recursively find all the '1's.
 * And change the value to be '0'. Thus, we could find the answer.
 *
 * And we could use another way to solve this problem, we could first calculate
 * all the '1's. And we use union find to connect, when calling connect one time
 * we delete the counter.
 */

// @lc code=start
class Solution {
private:
  // Defines the direction for easy compute
  int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  // Define the Disjoint set
  class DisjointSet {
  private:
    vector<int> data;

  public:
    int counter{};

    DisjointSet(int n) {
      data.resize(n);
      for (int i = 0; i < n; ++i) {
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
      if (rootI == rootJ)
        return;
      data[rootI] = rootJ;
      counter--;
    }

    bool isConnect(int i, int j) { return root(i) == root(j); }
  };

  bool isValid(int i, int j, int m, int n) {
    if (i < 0 || i >= m || j < 0 || j >= n) {
      return false;
    }
    return true;
  }

  void dfsSolutionHelper(vector<vector<char>> &grid, int i, int j, int m,
                         int n) {
    if (isValid(i, j, m, n) && grid[i][j] == '1') {
      grid[i][j] = '0';
      for (int k = 0; k < 4; ++k) {
        int nextI = i + dirs[k][0];
        int nextJ = j + dirs[k][1];
        dfsSolutionHelper(grid, nextI, nextJ, m, n);
      }
    }
  }

public:
  int dfsSolution(vector<vector<char>> &grid) {
    int m = grid.size();
    int n = grid[0].size();

    int ans = 0;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == '1') {
          ans++;
          dfsSolutionHelper(grid, i, j, m, n);
        }
      }
    }
    return ans;
  }

  int unionFindSolution(vector<vector<char>> &grid) {
    int m = grid.size();
    int n = grid[0].size();

    DisjointSet set{m * n};

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == '1') {
          set.counter++;
        }
      }
    }

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == '1') {
          for (int k = 0; k < 4; ++k) {
            int nextI = i + dirs[k][0];
            int nextJ = j + dirs[k][1];

            if (isValid(nextI, nextJ, m, n) && grid[nextI][nextJ] == '1') {
              set.connect(i * n + j, nextI * n + nextJ);
            }
          }
        }
      }
    }

    return set.counter;
  }

  int numIslands(vector<vector<char>> &grid) { return unionFindSolution(grid); }
};
// @lc code=end
