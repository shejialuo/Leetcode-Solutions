/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] Count and Say
 */

#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
  string countAndSay(int n) {
    string ans = "1";
    for(size_t i = 1; i < n; ++i) {
      string temp {};
      size_t sameLength = 1;
      for(size_t j = 0; j < ans.size() - 1; ++j) {
        if(ans[j] == ans[j + 1]) {
          sameLength++;
        } else {
          temp += (to_string(sameLength)) + ans[j];
          sameLength = 1;
        }
      }
      temp += (to_string(sameLength)) + ans.back();
      ans = move(temp);
    }
    return ans;
  }
};
// @lc code=end

