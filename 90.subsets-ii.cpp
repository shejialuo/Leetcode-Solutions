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

  void subsetsMathWay(vector<vector<int>> &ans, vector<int> &nums, int index) {

    if (index < nums.size()) {

      int currentSize = ans.size();
      for (int i = 0; i < currentSize; i++) {
        ans.push_back(ans[i]);
      }
      for (int i = currentSize; i < ans.size(); i++) {
        ans[i].push_back(nums[index]);
      }

      while (index + 1 < nums.size() && nums[index + 1] == nums[index]) {

        int size = ans.size();

        for (int i = currentSize; i < size; i++) {
          ans.push_back(ans[i]);
        }

        for (int i = size; i < ans.size(); i++) {
          ans[i].push_back(nums[index]);
        }

        currentSize = size;
        index++;
      }
      subsetsMathWay(ans, nums, index + 1);
    }
  }

public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans{};

    // ans.push_back({});
    // subsetsMathWay(ans, nums, 0);
    // return ans;

    vector<int> path{};
    subsetsWithDupHelper(0, nums, path, ans);
    return ans;
  }
};
// @lc code=end
