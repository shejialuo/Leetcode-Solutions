/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

#include <vector>
using namespace std;

/*
  * It is a simple question.
*/

// @lc code=start
class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result {};
    if (numRows >= 1) {
      result.push_back(vector<int>{1});
    }
    if (numRows >= 2) {
      result.push_back(vector<int>{1,1});
    }
    for(int i = 2; i < numRows; ++i) {
      vector<int> rowVector{1};
      for(size_t j = 0; j < result.back().size() - 1; ++j) {
        rowVector.push_back(result.back()[j] + result.back()[j + 1]);
      }
      rowVector.push_back(1);
      result.push_back(std::move(rowVector));
    }
    return result;
  }
};
// @lc code=end

