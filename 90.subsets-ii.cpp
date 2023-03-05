/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] Subsets II
 */

#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
private:
  void subsetsWithDupHelper(int start, vector<int> &nums, vector<int> &path,
                            vector<vector<int>> &ans) {
    ans.push_back(path);

    for (int i = start; i < nums.size(); i++) {
      if (i != start && nums[i] == nums[i - 1]) {
        continue;
      }
      path.push_back(nums[i]);
      subsetsWithDupHelper(i + 1, nums, path, ans);
      path.pop_back();
    }
  }

public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans{};
    vector<int> path{};
    subsetsWithDupHelper(0, nums, path, ans);
    return ans;
  }
};
// @lc code=end
