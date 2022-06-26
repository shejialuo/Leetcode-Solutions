/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

#include <vector>
#include <string>
using namespace std;

// @lc code=start
class Solution {
private:
  void helper(string& s, vector<string>& ans,
              int i, int n, int leftBracket, int rightBracket) {
    // end case
    if(i == 2 * n) {
      ans.push_back(s);
      return;
    }

    if(leftBracket != n) {
      s[i] = '(';
      helper(s , ans, i + 1 , n, leftBracket + 1, rightBracket);
    }
    if(rightBracket < leftBracket) {
      s[i] = ')';
      helper(s, ans, i + 1, n, leftBracket, rightBracket + 1);
    }

  }
public:
  vector<string> generateParenthesis(int n) {
    vector<string> ans{};
    string s {};
    s.resize(2 * n);
    helper(s, ans, 0, n, 0, 0);
    return ans;
  }
};
// @lc code=end

