/*
 * @lc app=leetcode.cn id=1020 lang=cpp
 *
 * [1020] Number of Enclaves
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
private:
  vector<vector<int>> dirs{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
  bool isValid(int i, int j, int row, int column) {
    return i >= 0 && i < row && j >= 0 && j < column;
  }
  void numEnclavesHelper(vector<vector<int>> &grid, int i, int j) {
    if (!isValid(i, j, grid.size(), grid[0].size()) || grid[i][j] != 1) {
      return;
    }
    grid[i][j] = -1;
    for (int k = 0; k < 4; ++k) {
      int ni = i + dirs[k][0];
      int nj = j + dirs[k][1];
      numEnclavesHelper(grid, ni, nj);
    }
  }

public:
  int numEnclaves(vector<vector<int>> &grid) {
    if (grid.empty())
      return 0;
    int row = grid.size();
    int column = grid[0].size();
    for (int i = 0; i < row; ++i) {
      numEnclavesHelper(grid, i, 0);
      numEnclavesHelper(grid, i, column - 1);
    }
    for (int i = 0; i < column; ++i) {
      numEnclavesHelper(grid, 0, i);
      numEnclavesHelper(grid, row - 1, i);
    }
    int res = 0;
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < column; ++j) {
        res += grid[i][j] == 1;
      }
    }
    return res;
  }
};
// @lc code=end
