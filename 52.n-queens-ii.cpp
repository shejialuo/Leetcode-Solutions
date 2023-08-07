/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N-Queens II
 */

#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
private:
  bool isValid(int row, int col, vector<string> &one, int n) {

    for (int i = 0; i < row; i++) {
      if (one[i][col] == 'Q') {
        return false;
      }
    }

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
      if (one[i][j] == 'Q') {
        return false;
      }
    }

    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
      if (one[i][j] == 'Q') {
        return false;
      }
    }
    return true;
  }
  void solveNQueensHelper(int i, int n, int &ans, vector<string> &one) {
    if (i == n) {
      ans++;
      return;
    }

    for (int j = 0; j < n; ++j) {
      if (isValid(i, j, one, n)) {
        one[i][j] = 'Q';
        solveNQueensHelper(i + 1, n, ans, one);
        one[i][j] = '.';
      }
    }
  }

public:
  int totalNQueens(int n) {
    int ans{0};
    vector<string> one(n, string(n, '.'));
    solveNQueensHelper(0, n, ans, one);
    return ans;
  }
};
// @lc code=end
