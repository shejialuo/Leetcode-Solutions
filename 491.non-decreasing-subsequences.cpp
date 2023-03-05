/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] Non-decreasing Subsequences
 */

#include <unordered_set>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
private:
  void findSubsequencesHelper(int start, int pre, vector<int> &nums,
                              vector<int> &path, vector<vector<int>> &ans) {

    if (path.size() >= 2) {
      ans.push_back(path);
    }

    unordered_set<int> visited{};
    for (int i = start; i < nums.size(); i++) {
      if (pre > nums[i] || visited.count(nums[i])) {
        continue;
      }
      visited.insert(nums[i]);
      path.push_back(nums[i]);
      findSubsequencesHelper(i + 1, nums[i], nums, path, ans);
      path.pop_back();
    }
  }

public:
  vector<vector<int>> findSubsequences(vector<int> &nums) {
    vector<vector<int>> ans{};
    vector<int> path{};
    findSubsequencesHelper(0, -101, nums, path, ans);
    return ans;
  }
};
// @lc code=end
