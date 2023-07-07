/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 3Sum
 */

#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

/*
 * It is easy for us to think about two-sum. We could easily
 * convert the problem to two-sum. However, the problem is
 * to make sure that the answer do not contain duplicate
 * triplets. It is hard.
 */

// @lc code=start
class Solution {
private:
  vector<vector<int>> threeSumHash(vector<int> &nums) {
    vector<vector<int>> ans{};
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
      // When we find a positive number, there is no need to continue
      if (nums[i] > 0) {
        break;
      }
      // We should continue when the situation is as the previous.
      // We have already deal with the `nums[i - 1]` So if
      // `nums[i] == nums[i - 1]` we should continue.
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      unordered_set<int> hash{};
      // Here we have already converted the three-sum problem to the
      // two-sum problem.
      for (int j = i + 1; j < nums.size(); ++j) {
        // We should drop the equal number
        if (j > i + 2 && nums[j] == nums[j - 1] && nums[j - 1] == nums[j - 2]) {
          continue;
        }
        int num = 0 - nums[i] - nums[j];
        if (hash.count(num)) {
          ans.push_back(vector<int>{nums[i], nums[j], num});
          // Here, we make sure that when there is multiple equal `nums[j]`
          // we only add it once.
          hash.erase(num);
        } else {
          hash.insert(nums[j]);
        }
      }
    }
    return ans;
  }
  vector<vector<int>> threeSumTwoPointer(vector<int> &nums) {
    vector<vector<int>> ans{};
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
      // We should continue when the situation is as the previous.
      // We have already deal with the `nums[i - 1]` So if
      // `nums[i] == nums[i - 1]` we should continue.
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      int start = i + 1, end = nums.size() - 1;
      while (start < end) {
        if (nums[i] + nums[start] + nums[end] == 0) {
          ans.push_back(vector<int>{nums[i], nums[start], nums[end]});
          while (start < end && nums[start] == nums[start + 1]) {
            start++;
          }
          while (start < end && nums[end] == nums[end - 1]) {
            end--;
          }
          start++;
          end--;
        } else if (nums[i] + nums[start] + nums[end] > 0) {
          end--;
        } else {
          start++;
        }
      }
    }
    return ans;
  }

public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    return threeSumTwoPointer(nums);
  }
};
// @lc code=end
