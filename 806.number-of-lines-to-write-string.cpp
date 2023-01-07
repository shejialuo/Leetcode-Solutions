/*
 * @lc app=leetcode.cn id=806 lang=cpp
 *
 * [806] Number of Lines To Write String
 */

#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  vector<int> numberOfLines(vector<int> &widths, string s) {
    int pixel = 0;
    int line = 1;
    for (auto c : s) {
      if (pixel + widths[c - 'a'] > 100) {
        line++;
        pixel = 0;
      }
      pixel += widths[c - 'a'];
    }
    return vector<int>{line, pixel};
  }
};
// @lc code=end
