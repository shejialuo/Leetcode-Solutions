/*
 * @lc app=leetcode.cn id=1629 lang=cpp
 *
 * [1629] Slowest Key
 */

#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  char slowestKey(vector<int> &releaseTimes, string keysPressed) {
    char ans{};
    int startTime = 0, duration = 0;

    for (int i = 0; i < releaseTimes.size(); i++) {
      if (releaseTimes[i] - startTime > duration) {
        duration = releaseTimes[i] - startTime;
        ans = keysPressed[i];
      } else if (releaseTimes[i] - startTime == duration) {
        if (keysPressed[i] > ans) {
          ans = keysPressed[i];
        }
      }
      startTime = releaseTimes[i];
    }

    return ans;
  }
};
// @lc code=end
