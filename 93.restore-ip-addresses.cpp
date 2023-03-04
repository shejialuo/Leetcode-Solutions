/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 */

#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
private:
  void restoreIpAddressesHelper(int start, int field, string &s,
                                vector<string> &one, vector<string> &ans) {
    if (field > 4) {
      return;
    }

    if (start >= s.size()) {
      if (field == 4) {
        string result{};
        for (int i = 0; i < one.size() - 1; ++i) {
          result += one[i] + ".";
        }
        result += one.back();
        ans.push_back(std::move(result));
      }
      return;
    }

    int length = 3;
    if (s.size() - start < 3) {
      length = s.size() - start;
    }

    if (s[start] == '0') {
      length = 1;
    }

    for (int i = 0; i < length; ++i) {
      string sub = s.substr(start, i + 1);
      if (stoi(sub) <= 255) {
        one.push_back(sub);
        restoreIpAddressesHelper(start + i + 1, field + 1, s, one, ans);
        one.pop_back();
      }
    }
  }

public:
  vector<string> restoreIpAddresses(string s) {
    vector<string> ans{};
    vector<string> one{};
    restoreIpAddressesHelper(0, 0, s, one, ans);
    return ans;
  }
};
// @lc code=end
