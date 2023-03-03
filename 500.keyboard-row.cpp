/*
 * @lc app=leetcode.cn id=500 lang=cpp
 *
 * [500] Keyboard Row
 */

#include <cctype>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
private:
  void helper(unordered_map<char, int> &table, string &level, int l) {
    for (char c : level) {
      table[c] = l;
      table[toupper(c)] = l;
    }
  }

public:
  vector<string> findWords(vector<string> &words) {
    unordered_map<char, int> table{};
    vector<string> keyboard{"qwertyuiop", "asdfghjkl", "zxcvbnm"};

    for (int i = 0; i < keyboard.size(); ++i) {
      helper(table, keyboard[i], i + 1);
    }

    vector<string> ans{};

    for (auto &&str : words) {
      bool isOneLevel = true;
      for (int j = 0; j < str.size() - 1; j++) {
        if (table[str[j]] != table[str[j + 1]]) {
          isOneLevel = false;
          break;
        }
      }
      if (isOneLevel) {
        ans.push_back(str);
      }
    }
    return ans;
  }
};
// @lc code=end
