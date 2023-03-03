/*
 * @lc app=leetcode.cn id=1487 lang=cpp
 *
 * [1487] Making File Names Unique
 */

#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  /**
   * @brief It may seem hard.. However, it is not so hard.
   * LOL.
   *
   */
  vector<string> getFolderNames(vector<string> &names) {
    std::unordered_map<std::string, int> table{};

    vector<string> ans{};

    for (auto &&name : names) {
      if (table[name] == 0) {
        table[name] = 1;
        ans.push_back(name);
      } else {
        int copyNum = table[name];
        std::string copyName = name + "(" + to_string(copyNum) + ")";
        while (table[copyName] != 0) {
          table[name]++;
          int copyNum = table[name];
          copyName = name + "(" + to_string(copyNum) + ")";
        }
        table[copyName] = 1;
        ans.push_back(copyName);
      }
    }
    return ans;
  }
};
// @lc code=end
