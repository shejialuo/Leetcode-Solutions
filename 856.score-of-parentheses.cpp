/*
 * @lc app=leetcode.cn id=856 lang=cpp
 *
 * [856] Score of Parentheses
 */

#include <string>
using namespace std;

// @lc code=start
class Solution {
private:
  int scoreOfParenthesesHelper(const string &s, int &index) {
    int sum = 0;

    while (index < s.size()) {
      if (s[index] == '(') {
        if (s[index + 1] == ')') {
          index += 2;
          sum += 1;
        } else {
          sum += 2 * scoreOfParenthesesHelper(s, ++index);
        }
      } else if (s[index] == ')') {
        index++;
        return sum;
      }
    }

    return sum;
  }

public:
  int scoreOfParentheses(string s) {
    int index = 0;
    return scoreOfParenthesesHelper(s, index);
  }
};
// @lc code=end
