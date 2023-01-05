/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

#include <string>
#include <vector>
using namespace std;

/*
 * We can easily use sliding window to solve this problem.
 * We just maintain `p.size()` window to hold the current
 * table, and compare with the goal.
 */

// @lc code=start
class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    vector<int> ans{};
    vector<int> goal(26, 0);
    vector<int> window(26, 0);
    for (char c : p)
      goal[c - 'a']++;
    for (int i = 0; i < s.size(); ++i) {
      window[s[i] - 'a']++;
      if (i >= p.size())
        window[s[i - p.size()] - 'a']--;
      if (goal == window)
        ans.push_back(i - p.size() + 1);
    }
    return ans;
  }
};
// @lc code=end
