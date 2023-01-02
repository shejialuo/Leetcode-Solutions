/*
 * @lc app=leetcode.cn id=771 lang=cpp
 *
 * [771] Jewels and Stones
 */

#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
  int numJewelsInStones(string jewels, string stones) {
    bool hash['z' - 'A' + 1]{};
    int ans = 0;
    for (char c : jewels) {
      hash[c - 'A'] = true;
    }
    for (char c : stones) {
      if (hash[c - 'A'])
        ans++;
    }
    return ans;
  }
};
// @lc code=end
