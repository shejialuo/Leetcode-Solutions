/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] Permutations
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
private:
  void permuteHelper(vector<int> &nums, vector<bool> &visited, vector<int> &one,
                     vector<vector<int>> &ans) {

    if (one.size() == nums.size()) {
      ans.push_back(one);
      return;
    }

    for (int i = 0; i < nums.size(); i++) {
      if (visited[i]) {
        continue;
      }
      visited[i] = true;
      one.push_back(nums[i]);
      permuteHelper(nums, visited, one, ans);
      one.pop_back();
      visited[i] = false;
    }
  }

public:
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> ans{};
    vector<int> one{};
    vector<bool> visited(nums.size(), false);
    permuteHelper(nums, visited, one, ans);
    return ans;
  }
};
// @lc code=end
