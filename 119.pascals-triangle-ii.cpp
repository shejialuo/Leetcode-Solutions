/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  vector<int> getRow(int rowIndex) {
    if (rowIndex == 0) {
      return vector<int>{1};
    }
    if (rowIndex == 1) {
      return vector<int>{1, 1};
    }

    vector<int> ans{1, 1};

    for (int i = 2; i <= rowIndex; ++i) {
      vector<int> rowVector{1};
      for (size_t j = 0; j < ans.size() - 1; ++j) {
        rowVector.push_back(ans[j] + ans[j + 1]);
      }
      rowVector.push_back(1);
      ans = std::move(rowVector);
    }
    return ans;
  }
};
// @lc code=end
