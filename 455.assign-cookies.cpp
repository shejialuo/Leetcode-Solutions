/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] Assign Cookies
 */

#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  /**
   * @brief This is a problem for greedy, it is easy
   * to think to solve this question by allocating
   * each cookie to minimum.
   */
  int findContentChildren(vector<int> &g, vector<int> &s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int num = 0;
    for (int i = 0, j = 0; i < g.size() && j < s.size(); ++j) {
      if (s[j] >= g[i]) {
        num++;
        i++;
      }
    }
    return num;
  }
};
// @lc code=end
