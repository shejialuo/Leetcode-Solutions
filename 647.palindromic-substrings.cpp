/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  int countSubstrings(string s) {
    int begin = 0, length = 1;
    bool direction = true;

    int start = s.size() - 1;
    int ans = 0;

    while (start >= 0) {
      for (int i = 0; i < 2 && start + i < s.size(); i++) {
        int localStart = start, localEnd = start + i;
        bool previous = false;
        while (localStart >= 0 && localEnd < s.size()) {
          if (localStart == localEnd) {
            previous = true;
          } else if (localStart + 1 == localEnd &&
                     s[localStart] == s[localEnd]) {
            previous = true;
          } else {
            previous = previous && s[localStart] == s[localEnd];
          }

          if (previous) {
            ans++;
          } else {
            // If we find one is not, we should stop the iteration.
            break;
          }
          localStart--;
          localEnd++;
        }
      }
      start--;
    }

    return ans;
  }
};
// @lc code=end
