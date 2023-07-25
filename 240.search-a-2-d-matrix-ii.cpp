/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int x = 0, y = matrix[0].size() - 1;
    while (x < matrix.size() && y >= 0) {
      if (matrix[x][y] == target) {
        return true;
      } else if (matrix[x][y] > target) {
        y--;
      } else {
        x++;
      }
    }
    return false;
  }
};
// @lc code=end
