/*
 * @lc app=leetcode.cn id=984 lang=cpp
 *
 * [984] String Without AAA or BBB
 */

#include <string>
using namespace std;

// @lc code=start
class Solution {
private:
  /**
   * @brief The easiest way is to think about the dfs way, it is not
   * difficult. However, this would exceed time limit.
   *
   */
  bool strWithout3a3bHelper(int index, int remainA, int remainB, string &str,
                            int windowA, int windowB) {
    if (index == str.size()) {
      return true;
    }

    int nextWindowA = windowA;
    int nextWindowB = windowB;

    if (index >= 2) {
      str[index - 2] == 'a' ? nextWindowA-- : nextWindowB--;
    }

    if (remainA > 0 && windowA != 2) {
      str[index] = 'a';
      nextWindowA++;

      if (strWithout3a3bHelper(index + 1, remainA - 1, remainB, str,
                               nextWindowA, nextWindowB)) {
        return true;
      }
      nextWindowA--;
    }

    if (remainB > 0 && windowB != 2) {
      str[index] = 'b';
      nextWindowB++;
      if (strWithout3a3bHelper(index + 1, remainA, remainB - 1, str,
                               nextWindowA, nextWindowB)) {
        return true;
      }
      nextWindowB--;
    }
    return false;
  }

public:
  string strWithout3a3b(int a, int b) {
    // string ans(a + b, ' ');
    // strWithout3a3bHelper(0, a, b, ans, 0, 0);
    // return ans;

    // We should convert this question, it is easy for us to
    // think about the combination.

    // When a > b, we should do aabaab....
    // When b > a, we should do bbabba....

    string ans{};
    while (a != 0 || b != 0) {

      if (b == 0) {
        for (int i = 0; i < a; ++i) {
          ans += 'a';
        }
        a = 0;
      } else if (a == 0) {
        for (int i = 0; i < b; ++i) {
          ans += 'b';
        }
        b = 0;
      } else if (a == b) {
        ans += "ab";
        a--;
        b--;
      } else if (a > b) {
        ans += "aab";
        a -= 2;
        b--;
      } else if (a < b) {
        ans += "bba";
        b -= 2;
        a--;
      }
    }
    return ans;
  }
};
// @lc code=end
