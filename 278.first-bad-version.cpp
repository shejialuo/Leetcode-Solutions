/*
 * @lc app=leetcode.cn id=278 lang=cpp
 *
 * [278] First Bad Version
 */

extern bool isBadVersion(int version);

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
  int firstBadVersion(int n) {
    int start = 1, end = n;
    while (start < end) {
      int mid = (end - start) / 2 + start;
      if (isBadVersion(mid)) {
        end = mid;
      } else {
        start = mid + 1;
      }
    }
    return start;
  }
};
// @lc code=end
