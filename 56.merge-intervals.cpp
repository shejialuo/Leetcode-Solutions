/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

#include <algorithm>
#include <vector>
using namespace std;

/*
 * It seems difficult to merge the interval. So we should simplify
 * the questions just by sort the interval by the first element.
 * For the interval [ni, mi], we let n0 < n1 < n2 < ... < ni`, thus
 * we have three different situations:
 *   1. When n1 > m0, the interval becomes two [n0, m0], [n1, m1]
 *   2. When n1 < m0 and m1 <= m0, the interval becomes [n0, m0]
 *   3. When n1 < m0 and m1 > m0, the interval becomes [n0, m1]
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    vector<vector<int>> ans{};
    sort(intervals.begin(), intervals.end(),
         [](const vector<int> &interval1, const vector<int> &interval2) {
           return interval1[0] < interval2[0];
         });
    for (vector<int> &interval : intervals) {
      if (ans.empty()) {
        ans.push_back(interval);
      } else {
        vector<int> &current = ans.back();
        if (interval[0] > current[1]) {
          ans.push_back(interval);
        } else if (interval[1] <= current[1]) {
          continue;
        } else {
          current[1] = interval[1];
        }
      }
    }

    return ans;
  }
};
// @lc code=end
