/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  /**
   * @brief In the question 95, we have formed a idea. In order to get
   * the ith root tree, we recursively solve the problem [1.. i -1]
   * and [i + 1 .. n]. And we combine the tree node, actually it is
   * cartesian product.
   *
   * We mathematically solve this problem.
   *
   * F(i, n): ith as root, and the length is n binary tree sum
   * G(n) = \sum_{i = 1} ^{n} (F(i, n))
   *
   * We could easily get the F(i ,n) = G(i - 1 - 1 + 1) * G (n - (i + 1) + 1)
   *                                 = G(i - 1) * G(n - i)
   * G(n) = \sum_{i = 1} ^{n} (G(i - 1) * G(n - i))
   */
  int numTrees(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
      for (int j = 1; j <= i; j++) {
        dp[i] += dp[j - 1] * dp[i - j];
      }
    }
    return dp.back();
  }
};
// @lc code=end
