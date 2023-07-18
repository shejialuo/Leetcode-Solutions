/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] Subsets
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
private:
  /**
   * @brief Here, we still use the backtracking, in the combination
   * problem, we pay attention to the leaf. In this problem, we pay
   * attention to the path.
   *
   */
  void subsetsHelper(int start, vector<int> &nums, vector<int> &path,
                     vector<vector<int>> &ans) {

    ans.push_back(path);

    for (int i = start; i < nums.size(); ++i) {
      path.push_back(nums[i]);
      subsetsHelper(i + 1, nums, path, ans);
      path.pop_back();
    }
  }

  void subsetsMathWay(vector<vector<int>> &ans, vector<int> &nums, int index) {

    if (index < nums.size()) {

      int currentSize = ans.size();

      for (int i = 0; i < currentSize; i++) {
        ans.push_back(ans[i]);
      }

      for (int i = currentSize; i < ans.size(); i++) {
        ans[i].push_back(nums[index]);
      }

      subsetsMathWay(ans, nums, index + 1);
    }
  }

public:
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> ans{};

    // ans.push_back(vector<int>{});
    // subsetsMathWay(ans, nums, 0);
    // return ans;

    vector<int> path{};
    subsetsHelper(0, nums, path, ans);
    return ans;
  }
};
// @lc code=end
