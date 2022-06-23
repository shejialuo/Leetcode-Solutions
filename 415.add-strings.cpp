/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] Add Strings
 */

#include <string>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
private:
  int charToInt(char c) {
    return c - '0';
  }
  char intToChar(int n) {
    return n + '0';
  }
public:
  string addStrings(string num1, string num2) {
    int c = 0;
    int i = num1.size() - 1, j = num2.size() - 1;
    string ans {};
    int k = max(i, j) + 1;
    ans.resize(k + 1);
    while(i >= 0 && j >= 0) {
      int sum = charToInt(num1[i--]) + charToInt(num2[j--]) + c;
      ans[k--] = intToChar(sum % 10);
      c = sum / 10;
    }
    while(i >= 0) {
      int sum = charToInt(num1[i--]) + c;
      ans[k--] = intToChar(sum % 10);
      c = sum / 10;
    }
    while(j >= 0) {
      int sum = charToInt(num2[j--]) + c;
      ans[k--] = intToChar(sum % 10);
      c = sum / 10;
    }
    if(c != 0) {
      ans[k] = intToChar(c);
    } else {
      ans.erase(0, 1);
    }
    return ans;
  }
};
// @lc code=end

