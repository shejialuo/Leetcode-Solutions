/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
private:
  /**
   * @brief This problem is very interesting. We should divide the problem
   * into smaller. For eaxmple, For "c1c2c3c4", we could divide it to the
   * subproblem. "c1 <subproblem>", "c1c2<subproblem>" and so on
   *
   */

  bool isPalindrome(string &str) {
    for (int i = 0, j = str.size() - 1; i < j; i++, j--) {
      if (str[i] != str[j]) {
        return false;
      }
    }
    return true;
  }

  void partitionHelper(int startIndex, string &s, vector<string> &one,
                       vector<vector<string>> &ans) {
    if (startIndex >= s.size()) {
      ans.push_back(one);
      return;
    }
    int start = startIndex;
    for (int i = startIndex; i < s.size(); i++) {
      string sub = s.substr(start, i - start + 1);
      if (isPalindrome(sub)) {
        one.push_back(sub);
        partitionHelper(i + 1, s, one, ans);
        one.pop_back();
      }
    }
  }

public:
  vector<vector<string>> partition(string s) {
    vector<vector<string>> ans{};
    vector<string> one{};
    partitionHelper(0, s, one, ans);
    return ans;
  }
};
// @lc code=end
