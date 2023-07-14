/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

#include <string>
#include <vector>
using namespace std;

/*
 * It's clear that every wel-formed parentheses has
 * 2 * n size. So we should do static memory operation.
 * The question is that how to generate the well-formed
 * parentheses, it's super easy, we should count there
 * are how many left brackets and right brackets we have
 * assigned to make sure that the parentheses is well-formed.
 */

// @lc code=start
class Solution {
private:
  void helper(string &s, vector<string> &ans, int i, int leftBracket,
              int rightBracket) {

    if (i == s.size()) {
      ans.push_back(s);
      return;
    }

    if (leftBracket < s.size() / 2) {
      s[i] = '(';
      helper(s, ans, i + 1, leftBracket + 1, rightBracket);
    }

    if (rightBracket < leftBracket) {
      s[i] = ')';
      helper(s, ans, i + 1, leftBracket, rightBracket + 1);
    }
  }

public:
  vector<string> generateParenthesis(int n) {
    vector<string> ans{};
    string s{};
    s.resize(2 * n);
    helper(s, ans, 0, 0, 0);
    return ans;
  }
};
// @lc code=end
