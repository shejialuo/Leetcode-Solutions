/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] Add Binary
 */

#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
  /**
   * @brief The idea here is simple. But do remember we should
   * resize the answer's size to be static which should
   * improve the performance. There are two situations:
   *   + the length is equal to the max length of a and b
   *   + the length is max length of a and b plus 1
   *
   */
  string addBinary(string a, string b) {
    string ans{};
    int length = max(a.size(), b.size()) + 1;
    ans.resize(length);

    int index = length - 1, i = a.size() - 1, j = b.size() - 1;
    int c = 0;
    while (i >= 0 || j >= 0) {
      int num1 = i >= 0 ? (a[i] - '0') : 0;
      int num2 = j >= 0 ? (b[j] - '0') : 0;
      int sum = (num1 + num2 + c) % 2;
      c = (num1 + num2 + c) / 2;
      ans[index--] = sum + '0';
      i--;
      j--;
    }
    if (c != 0) {
      ans[index] = c + '0';
    } else {
      ans.erase(0, 1);
    }
    return ans;
  }
};
// @lc code=end
