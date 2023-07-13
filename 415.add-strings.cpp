/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] Add Strings
 */

#include <iostream>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
  string addStrings(string num1, string num2) {
    int c = 0;
    int i = num1.size() - 1, j = num2.size() - 1;
    string ans{};
    int length = max(i, j) + 1;
    ans.resize(length + 1);
    while (i >= 0 || j >= 0) {

      int val1 = i >= 0 ? num1[i] - '0' : 0;
      int val2 = j >= 0 ? num2[j] - '0' : 0;

      int sum = val1 + val2 + c;
      ans[length--] = (sum % 10 + '0');
      c = sum / 10;
      i--;
      j--;
    }

    if (c != 0) {
      ans[length] = c + '0';
    } else {
      ans.erase(0, 1);
    }
    return ans;
  }
};
// @lc code=end
